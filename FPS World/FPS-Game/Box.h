#pragma once

// THESE HEADER INCLUDES SHOULD NOT BE HERE 
// BUT THE COMPILER FREAKED OUT AND 
// IT WOULDN'T COMPILE IF I DIDN'T INCLUDE THEM HERE
#include <GL\glew.h>
#include <GL\glfw.h>

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

class GPUProgram;
class Camera;
class Light;
class Texture;

class Box
{
	private:
		GPUProgram* shader;
		Texture* texture;
		GLuint vertexArrayID;
		GLuint vertexBuffer;
		glm::mat4 transform;

		GLfloat shininess;
		glm::vec3 specularColor;

	public:
		Box();
		~Box();

		void prepareMaterial(Camera* camera);
		void setShininess(GLfloat shine);
		void setSpecularColor(glm::vec3 color);

		GPUProgram* getShader();
		Texture* getTexture();
		GLuint getVAO();

		GLfloat getShininess();
		glm::vec3 getSpecularColor();
};