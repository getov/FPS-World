#pragma once

class GPUProgram;
class Camera;

class Player
{
	private:
		GPUProgram* shader;
		Camera* camera;
		GLuint vertexArrayID;
		GLuint vertexBuffer;

	public:
		Player();
		~Player();

		void prepare();
		void drawPlayer();
};