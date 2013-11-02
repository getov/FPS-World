#pragma once

class GPUProgram;
class Camera;
class Light;

class AnotherBox
{
	private:
		GPUProgram* shader;
		GLuint vertexArrayID;
		GLuint vertexBuffer;
		glm::mat4 transform;

		GLfloat shininess;
		glm::vec3 specularColor;
		glm::vec4 m_color;

	public:
		AnotherBox();
		AnotherBox(glm::vec4& color);
		~AnotherBox();

		void prepareMaterial(Camera* camera);
		void drawBox(Camera* camera, Light* gLight);

		void setShininess(GLfloat shine);
		void setSpecularColor(glm::vec3 color);
};