#include <GL\glew.h>
#include <GL\glfw.h>

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

#include "Light.h"

Light::Light()
	: color(1.0, 1.0, 1.0)
	, position(0.0, 0.0, 0.0)
	, attMult(0.2)
	, ambientCoefficient(0.02)
{
}

Light::Light(const glm::vec3& color, const glm::vec3& position,
			  const float& attenuationMult, const float& ambient)
	: color(color)
	, position(position)
	, attMult(attenuationMult)
	, ambientCoefficient(ambient)
{
}

Light::~Light()
{
}