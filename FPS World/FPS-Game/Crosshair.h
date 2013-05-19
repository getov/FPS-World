#pragma once

class GPUProgram;
class Player;

class Crosshair
{
	private:
		GPUProgram* shader;
		GLuint vertexArrayID;
		GLuint vertexBuffer;
		glm::mat4 transform;

	public:
		Crosshair();
		~Crosshair();

		void prepareMaterial();
		void drawCrosshair();
};