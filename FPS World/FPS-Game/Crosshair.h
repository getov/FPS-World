#pragma once

class GPUProgram;
class Camera;
class Player;

class Crosshair
{
	private:
		GPUProgram* shader;
		Camera* camera;
		GLuint vertexArrayID;
		GLuint vertexBuffer;
		glm::mat4 transform;

	public:
		Crosshair();
		~Crosshair();

		void prepareMaterial();
		void drawCrosshair();
};