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
		float moveSpeed;

	public:
		Player();
		~Player();

		void prepareMaterial();
		void drawPlayer();
		void updatePosition(float secondsElapsed);
};