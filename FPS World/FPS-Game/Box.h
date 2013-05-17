#pragma once

class GPUProgram;
class Camera;

class Box
{
	private:
		GPUProgram* shader;
		GLuint vertexArrayID;
		GLuint vertexBuffer;
		glm::mat4 transform;

	public:
		Box();
		~Box();

		void prepareMaterial(Camera* camera);
		void drawBox(Camera* camera);
};