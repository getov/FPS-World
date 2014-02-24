#pragma once

// THESE HEADER INCLUDES SHOULD NOT BE HERE 
// BUT THE COMPILER FREAKED OUT AND 
// IT WOULDN'T COMPILE IF I DIDN'T INCLUDE THEM HERE
#include <GL\glew.h>
#include <GL\glfw.h>

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

#include "IGeometry.h"

class GPUProgram;
class Camera;
class Light;
class Texture;

class Box : public IGeometry
{
	private:
		GPUProgram* shader;
		Texture* texture;
		GLuint vertexArrayID;
		GLuint vertexBuffer;
		glm::mat4 transform;

		GLfloat shininess;
		glm::vec3 specularColor;

		float moveSpeed;
		GLfloat degreesPerSecond;
		float degreesRotated;

	public:
		Box();
		~Box();

		void prepareMaterial();
		void setShininess(GLfloat shine);
		void setSpecularColor(glm::vec3 color);

		GPUProgram* getShader();
		Texture* getTexture();
		GLuint getVAO();

		GLfloat getShininess();
		glm::vec3 getSpecularColor();

		// functions for movement control over the box
		float getMoveSpeed();
		GLfloat getDegreesPerSecond();
		float getDegreesRotated();

		void setMoveSpeed(float speed);
		void setDegreesPerSecond(float degPerSecond);
		void setDegreesRotated(float degRotated);
};