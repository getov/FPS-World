#pragma once

class GPUProgram;
class Camera;

class AnotherBox
{
	private:
		GPUProgram* shader;
		GLuint vertexArrayID;
		GLuint vertexBuffer;
		glm::mat4 transform;

	public:
		AnotherBox();
		~AnotherBox();

		void prepareMaterial(Camera* camera);
		void drawBox(Camera* camera);
};