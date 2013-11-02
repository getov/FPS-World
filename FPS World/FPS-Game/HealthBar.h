#pragma once

class GPUProgram;

class HealthBar
{
	private:
		GPUProgram* shader;
		GLuint vertexArrayID;
		GLuint vertexBuffer;
		glm::mat4 transform;

		glm::vec3 m_color;

	public:
		HealthBar();
		~HealthBar();

		void prepareMaterial();
		void drawHealthBar();
};