#pragma once

class GPUProgram;

class HealthBar
{
	private:
		GPUProgram* shader;
		GLuint vertexArrayID;
		GLuint vertexBuffer;
		glm::mat4 transform;

	public:
		HealthBar();
		~HealthBar();

		void prepareMaterial();
		void drawHealthBar();
};