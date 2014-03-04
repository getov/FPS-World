#include <GL\glew.h>
#include <GL\glfw.h>

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

#include "Renderer.h"
#include "Projectile.h"

using namespace Util;

Renderer::Renderer()
	: shader(nullptr)
{
}

Renderer::Renderer(Camera* world, Light* light)
	: shader(nullptr)
	, world(world)
	, gLight(light)
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
	geometries.push_back(new Box(glm::vec4(1.0f, 1.0f, 1.0f, 0.0f),
								 "PhongReflectionTex.frag", true, "wooden-crate.jpg"));
	geometries.push_back(new Box(glm::vec4(0.0f, 0.5f, 0.7f, 0.0f),
								 "PhongReflection.frag"));

	geometries.push_back(new Projectile(glm::vec4(0.3f, 0.0f, 0.7f, 0.0f), 
										"PhongReflection.frag"));
	
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

		geomInstances[0]->transform = scale(0.3f, 0.2f, 0.2f) * translate(-2.0f, 1.0f, 0.0f);
		geomInstances[1]->transform = scale(1000.3f, 0.01f, 1000.3f)/* * translate(0.0f, 0.0f, 0.0f)*/;

		geomInstances.push_back(new GeometryInstance);
		geomInstances[2]->asset = geometries[1];
		geomInstances[2]->transform = scale(0.3f, 1.5f, 0.2f) * translate(1.0f, 1.0f, 0.0f);
	}
}

void Renderer::renderGeometries()
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
			shader->setUniform("tex", *texture);
		}
		else
		{
			shader->setUniform("m_color",  geomInstances[i]->asset->getDiffuseColor());
		}

		shader->setUniform("camera", world->matrix());
		shader->setUniform("model", geomInstances[i]->transform);

		shader->setUniform("material.shininess", asset->getShininess());
		shader->setUniform("material.specularColor", asset->getSpecularColor());
		shader->setUniform("light.position", gLight->position);
		shader->setUniform("light.intensities", gLight->color);
		shader->setUniform("light.attenuation", gLight->attMult);
		shader->setUniform("light.ambientCoefficient", gLight->ambientCoefficient);
		shader->setUniform("cameraPosition", world->cameraPosition());

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
	}

	if (!projectiles.empty())
	{
		for (auto proj = projectiles.begin(); proj != projectiles.end(); ++proj)
		{
			(*proj)->asset = dynamic_cast<IProjectile*>(geometries[2]);
			(*proj)->asset->position() += world->cameraPosition() * secondsElapsed;
			(*proj)->transform = translate((*proj)->asset->position().x,
										   (*proj)->asset->position().y,
										   -(*proj)->asset->position().z) *
										   scale(0.01f, 0.01f, 0.01f) *
										   rotate(45.0f, 0.0f, 0.0f, 1.0f) * world->orientation();
		}
	}

}

void Renderer::shoot()
{
	//ProjectileInstance* bullet = new ProjectileInstance;
	//glm::vec3 position = world->cameraPosition() + world->forward();
	//bullet->asset = dynamic_cast<IProjectile*>(geometries[2]);
	/*bullet->transform = translate(position.x,
								  position.y,
								  position.z) * scale(0.01f, 0.01f, 0.01f);*/
	projectiles.push_back(new ProjectileInstance);
	projectiles.back()->asset = dynamic_cast<IProjectile*>(geometries[2]);
	projectiles.back()->asset->position() = world->forward();
	projectiles.back()->transform = translate(projectiles.back()->asset->position().x,
										   projectiles.back()->asset->position().y,
										   projectiles.back()->asset->position().z) *
										   scale(0.01f, 0.01f, 0.01f) *
										   rotate(45.0f, 0.0f, 0.0f, 1.0f) * world->orientation();
}

void Renderer::createBox()
{
	GeometryInstance* box = new GeometryInstance;
	glm::vec3 position = world->cameraPosition() + world->forward() * 2.0f;
	box->asset = geometries[0];
	box->transform = translate(position.x, position.y, position.z) * scale(0.1f, 0.1f, 0.1f);
	geomInstances.push_back(box);
}

void Renderer::createBoxNoTex()
{
	GeometryInstance* box = new GeometryInstance;
	glm::vec3 position = world->cameraPosition() + world->forward() * 2.0f;
	box->asset = geometries[1];
	box->transform = translate(position.x, position.y, position.z) * scale(0.1f, 0.1f, 0.1f);
	geomInstances.push_back(box);
}

void Renderer::removeLastGeometry()
{
	if (geomInstances.size() > 3) // don't delete the first 3 geometries
	{
		GeometryInstance* tmp = geomInstances.back();

		geomInstances.pop_back();

		delete tmp;
	}
}
