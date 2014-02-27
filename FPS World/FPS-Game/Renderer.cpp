#include <GL\glew.h>
#include <GL\glfw.h>

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

#include "Renderer.h"

using namespace Util;

Renderer::Renderer()
	: shader(nullptr)
{
}

Renderer::~Renderer()
{
	// free the allocated memory
	for (auto i = geometries.begin(); i != geometries.end(); ++i)
	{
		delete *i;
	}

	for (auto i = geomInstances.begin(); i != geomInstances.end(); ++i)
	{
		delete *i;
	}
}

void Renderer::prepareSceneObjects()
{
	geometries.push_back(new Box);
	geometries.push_back(new Box(glm::vec4(0.0f, 0.5f, 0.7f, 0.0f),
								 "PhongReflection.frag", "wooden-crate.jpg", false));

	for (auto i = geometries.begin(); i != geometries.end(); ++i)
	{
		(*i)->prepareMaterial();
	}
}

void Renderer::createGeometryInstances()
{
	geomInstances.push_back(new GeometryInstance);
	geomInstances.push_back(new GeometryInstance);

	if (!geometries.empty())
	{
		geomInstances[0]->asset = geometries[0];
		geomInstances[1]->asset = geometries[0];

		geomInstances[0]->transform = translate(-1.0f, 0.0f, 0.0f) * scale(0.3f, 0.2f, 0.2f);
		geomInstances[1]->transform = scale(1000.3f, 0.01f, 1000.3f) * translate(0.0f, 0.0f, 0.0f);

		geomInstances.push_back(new GeometryInstance);
		geomInstances[2]->asset = geometries[1];
		geomInstances[2]->transform = translate(1.0f, 0.0f, 0.0f) * scale(0.3f, 0.2f, 0.2f);
	}	
}

void Renderer::renderGeometries(Camera& world, Light& gLight)
{
	shader = nullptr;

	for (int i = 0; i < geomInstances.size(); ++i)
	{
		IGeometry* asset = geomInstances[i]->asset;
		
		if (geomInstances[i]->asset->getShader() != shader)
		{
			if (shader)
			{
				shader->stopUsing();
			}

			shader = geomInstances[i]->asset->getShader();
			shader->use();
		}

		Texture* texture = asset->getTexture();
		if (texture)
		{
			//glActiveTexture(GL_TEXTURE0);
			//glBindTexture(texture->getTexType(), texture->getTexID());
			shader->setUniform("tex", *texture);
		}
		else
		{
			shader->setUniform("m_color",  geomInstances[i]->asset->getDiffuseColor());
		}

		shader->setUniform("camera", world.matrix());
		shader->setUniform("model", geomInstances[i]->transform);

		shader->setUniform("material.shininess", asset->getShininess());
		shader->setUniform("material.specularColor", asset->getSpecularColor());
		shader->setUniform("light.position", gLight.getPosition());
		shader->setUniform("light.intensities", gLight.getColor());
		shader->setUniform("light.attenuation", gLight.getAttenuation());
		shader->setUniform("light.ambientCoefficient", gLight.getAmbientCoefficient());
		shader->setUniform("cameraPosition", world.cameraPosition());

		glBindVertexArray(asset->getVAO());
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}

	// unbind
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
	shader->stopUsing();
}

void Renderer::updateScene(float secondsElapsed)
{
	if (!geomInstances.empty())
	{
		geomInstances[1]->asset->setDegreesRotated(secondsElapsed * geomInstances[1]->asset->getDegreesPerSecond() * 0.1);

		while (geomInstances[1]->asset->getDegreesRotated() > 360.f)
		{
			geomInstances[1]->asset->setDegreesRotated(-360.f);
		}

		geomInstances[1]->transform = translate(-1.0f, 0.0f, 0.0f) * scale(0.3f, 0.2f, 0.2f) *
									  rotate(geomInstances[1]->asset->getDegreesRotated(), 0, 1, 0);
	}
}

void Renderer::createBox(Camera& world, float secElapsed)
{
	GeometryInstance* box = new GeometryInstance;
	glm::vec3 position = world.cameraPosition() + world.forward() * 2.0f;
	box->asset = geometries[0];
	box->transform = translate(position.x, position.y, position.z) * scale(0.1f, 0.1f, 0.1f);
	geomInstances.push_back(box);
}

void Renderer::createBoxNoTex(Camera& world, float secElapsed)
{
	GeometryInstance* box = new GeometryInstance;
	glm::vec3 position = world.cameraPosition() + world.forward() * 2.0f;
	box->asset = geometries[1];
	box->transform = translate(position.x, position.y, position.z) * scale(0.1f, 0.1f, 0.1f);
	geomInstances.push_back(box);
}

void Renderer::removeLastGeometry()
{
	if (!geomInstances.empty())
	{
		GeometryInstance* tmp = geomInstances.back();

		geomInstances.pop_back();

		delete tmp;
	}
}
