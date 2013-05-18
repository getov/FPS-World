#include <GL\glew.h>
#include <GL\glfw.h>

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

#include "Light.h"

Light::Light()
{
}

Light::~Light()
{
}

void Light::setPosition(glm::vec3 lightPos)
{
	position = lightPos;
}

void Light::setColor(glm::vec3 lightColor)
{
	color = lightColor;
}

glm::vec3 Light::getPosition()
{
	return position;
}

glm::vec3 Light::getColor()
{
	return color;
}