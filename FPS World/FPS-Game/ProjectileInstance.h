#pragma once

#include "IProjectile.h"
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

class ProjectileInstance
{
public:
	ProjectileInstance();

	IProjectile* asset;
	glm::mat4 transform;
};