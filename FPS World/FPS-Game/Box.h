#pragma once


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
		glm::vec4 m_color;

		float moveSpeed;
		GLfloat degreesPerSecond;
		float degreesRotated;

		const char* fragShaderName;
		const char* textureName;
		bool useTexture;

	public:
		Box();
		Box(const glm::vec4& color, const char* fragShader, const char* texName, bool useTex = false);
		~Box();

		void prepareMaterial();
		void setShininess(GLfloat shine);
		void setSpecularColor(glm::vec3 color);

		GPUProgram* getShader();
		Texture* getTexture();
		GLuint getVAO();

		GLfloat getShininess();
		glm::vec3 getSpecularColor();
		glm::vec4 getDiffuseColor();

		// functions for movement control over the box
		float getMoveSpeed();
		GLfloat getDegreesPerSecond();
		float getDegreesRotated();

		void setMoveSpeed(const float& speed);
		void setDegreesPerSecond(const float& degPerSecond);
		void setDegreesRotated(const float& degRotated);
};