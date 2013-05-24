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
	boxI->transform = translate(-2.0f, 0.0f, 0.0f) * scale(0.30f, 0.30f, 0.30f);
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
	boxI->transform = rotate(45.0f, 0.0f, 1.0f, 0.0f) * translate(0.0f, 1.0f, 0.0f) * scale(0.30f, 0.30f, 0.30f);
	boxes.push_back(boxI);

	boxI = new BoxInstance;
	boxI->asset = box;
	boxI->transform = translate(-1.0f, 1.0f, 0.0f) * scale(0.30f, 0.30f, 0.30f);
	boxes.push_back(boxI);
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

		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, box->getVAO());
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8*sizeof(GLfloat), NULL);

		// connect the normal to the "vertNormal" attribute of the vertex shader
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_TRUE, 8*sizeof(GLfloat), (const GLvoid*)(5 * sizeof(GLfloat)));

		// connect the uv coords to the "vertTexCoord" attribute of the vertex shader
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_TRUE,  8*sizeof(GLfloat), (const GLvoid*)(3 * sizeof(GLfloat)));

		shader->setUniform("light.position", gLight->getPosition());
		shader->setUniform("light.intensities", gLight->getColor());

		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
}