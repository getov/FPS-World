#pragma once

class GPUProgram;
class Camera;

class TestObject
{
	private:
		GPUProgram* shader;
		Camera* camera;
		GLuint vertexArrayID;
		GLuint vertexBuffer;

	public:
		TestObject();
		~TestObject();

		void prepareMaterial();
		void drawObject();
};