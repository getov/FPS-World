#include <GL\glew.h>
#include <GL\glfw.h>

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

#include <vector>

#include "GPUProgram.h"
#include "Camera.h"
#include "Light.h"
#include "Box.h"
#include "BoxInstance.h"
#include "Renderer.h"
#include "Util.h"
#include "Texture.h"

using namespace Util;

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
	// free the allocated memory
	for (auto i = boxes.begin(); i != boxes.end(); ++i)
	{
		delete (*i);
	}

	glBindVertexArray(0);
}

void Renderer::createBoxInstances(Box* box, BoxInstance* boxI)
{
	boxI = new BoxInstance;
	boxI->asset = box;
	boxI->transform = translate(-1.0f, 0.0f, 0.0f) * scale(0.30f, 0.30f, 0.30f);
	boxes.push_back(boxI);
	
	boxI = new BoxInstance;
	boxI->asset = box;
	boxI->transform = translate(-2.0f, 0.0f, 1.0f) * scale(0.40f, 0.35f, 0.30f);
	boxes.push_back(boxI);

	boxI = new BoxInstance;
	boxI->asset = box;
	boxI->transform = translate(1.0f, 0.0f, 0.0f) * scale(0.40f, 0.35f, 0.30f);
	boxes.push_back(boxI);

	boxI = new BoxInstance;
	boxI->asset = box;
	boxI->transform = translate(0.0f, 0.7f, -2.0f) * scale(1.0f, 1.0f, 1.0f);
	boxes.push_back(boxI);

	/*boxI = new BoxInstance;
	boxI->asset = box;
	boxI->transform = rotate(45.0f, 0.0f, 1.0f, 0.0f) * translate(0.0f, 1.0f, 0.0f) * scale(0.30f, 0.30f, 0.30f);
	boxes.push_back(boxI);*/
/*
	boxI = new BoxInstance;
	boxI->asset = box;
	boxI->transform = translate(-1.0f, 1.0f, 0.0f) * scale(0.30f, 0.30f, 0.30f);
	boxes.push_back(boxI);*/
}

void Renderer::updateScene(float secondsElapsed)
{
	if (!boxes.empty())
	{
		for (int i = 0; i < 2; ++i)
		{
			boxes[i]->asset->setDegreesRotated((secondsElapsed * boxes[i]->asset->getDegreesPerSecond()) / 6.0); // divide by 6 for slower rotation

			while(boxes[i]->asset->getDegreesRotated() > 360.0f)
			{
				boxes[i]->asset->setDegreesRotated(-360.0f);
			}
		}

		boxes[0]->transform = translate(2.0f, 0.7f, 0.0f) * scale(0.30f, 0.30f, 0.30f) * rotate(boxes[0]->asset->getDegreesRotated(), 0, 1, 0);
		boxes[1]->transform = rotate(boxes[1]->asset->getDegreesRotated(), 0, 1, 0) * translate(1.0f, 2.3f, 1.0f) * scale(0.30f, 0.30f, 0.30f) *
							  rotate(boxes[1]->asset->getDegreesRotated() * 2.0, 0, -1, 0); // optional rotation for fun :)
	}
}

void Renderer::renderBoxInstances(Box* box, Camera* gWorld, Light* gLight)
{
	// render all the created instances in boxes
	for (auto boxI = boxes.begin(); boxI != boxes.end(); ++boxI)
	{
		box = (*boxI)->asset;
		GPUProgram* shader = box->getShader();

		shader->use();
		shader->setUniform("camera", gWorld->matrix());
		shader->setUniform("model", (*boxI)->transform);
		//shader->setUniform("tex", (*boxI)->asset->getTexture()->getTexID());

		shader->setUniform("material.shininess", box->getShininess());
		shader->setUniform("material.specularColor", box->getSpecularColor());
		shader->setUniform("light.position", gLight->getPosition());
		shader->setUniform("light.intensities", gLight->getColor());
		shader->setUniform("light.attenuation", gLight->getAttenuation());
		shader->setUniform("light.ambientCoefficient", gLight->getAmbientCoefficient());
		shader->setUniform("cameraPosition", gWorld->cameraPosition());

		Texture* texture = (*boxI)->asset->getTexture();
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(texture->getTexType(), texture->getTexID());

		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, box->getVAO());
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8*sizeof(GLfloat), NULL);

		// connect the normal to the "vertNormal" attribute of the vertex shader
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_TRUE, 8*sizeof(GLfloat), (const GLvoid*)(5 * sizeof(GLfloat)));

		// connect the uv coords to the "vertTexCoord" attribute of the vertex shader
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_TRUE,  8*sizeof(GLfloat), (const GLvoid*)(3 * sizeof(GLfloat)));

		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
}