#pragma once

#include <GL\glew.h>
#include <GL\glfw.h>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

#include "GPUProgram.h"
#include "Camera.h"
#include "Light.h"
#include "Texture.h"

class IGeometry
{
protected:
	glm::vec3 pos;

public:
	virtual ~IGeometry() {}

	virtual glm::vec3& position()
	{
		return pos;
	}

	virtual void prepareMaterial() = 0;

	virtual void setShininess(GLfloat shine) = 0;
	virtual void setSpecularColor(glm::vec3 color) = 0;

	virtual GPUProgram* getShader() = 0;
	virtual Texture* getTexture() = 0;
	virtual GLuint getVAO() = 0;

	virtual GLfloat getShininess() = 0;
	virtual glm::vec3 getSpecularColor() = 0;
	virtual glm::vec4 getDiffuseColor() = 0;


	// movement
	virtual float getMoveSpeed() = 0;
	virtual GLfloat getDegreesPerSecond() = 0;
	virtual float getDegreesRotated() = 0;

	virtual void setMoveSpeed(const float& speed) = 0;
	virtual void setDegreesPerSecond(const float& degPerSecond) = 0;
	virtual void setDegreesRotated(const float& degRotated) = 0;
};