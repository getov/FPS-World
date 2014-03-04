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

	/**
	 * @brief - Setup the buffers, vertex data
	 * and materials for the geometry
	*/
	virtual void prepareMaterial() = 0;

	virtual GPUProgram* getShader() = 0;
	virtual Texture* getTexture() = 0;
	virtual GLuint getVAO() = 0;

	// Color
	virtual void setShininess(GLfloat shine)	   = 0;
	virtual void setSpecularColor(glm::vec3 color) = 0;

	virtual GLfloat   getShininess()	 = 0;
	virtual glm::vec3 getSpecularColor() = 0;

	/**
	 * @brief - Function that returns the diffuse color
	 * of a geometry
	 * @return - returns glm::vec4 that represents the defuse color
	 * The range of each component (R, G, B, A) is in the range [0.0 , 1.0]
	*/
	virtual glm::vec4 getDiffuseColor()  = 0;


	// movement
	virtual float	getMoveSpeed()		  = 0;
	virtual float	getDegreesRotated()	  = 0;
	virtual GLfloat getDegreesPerSecond() = 0;

	/**
	 * @brief - Set speed for the movement of a geometry
	 * @param speed - the speed of movement
	*/
	virtual void setMoveSpeed(const float& speed)				= 0;
	virtual void setDegreesPerSecond(const float& degPerSecond) = 0;
	virtual void setDegreesRotated(const float& degRotated)		= 0;
};