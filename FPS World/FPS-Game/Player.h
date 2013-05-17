#pragma once

class GPUProgram;
class Camera;

class Player
{
	private:
		GPUProgram* shader;
		GLuint vertexArrayID;
		GLuint vertexBuffer;

		GLfloat degreesPerSecond;
		GLfloat degreesRotated;
		float moveSpeed;
		float mouseSensitivity;
		int mouseX;
		int mouseY;

	public:
		Player();
		~Player();

		void prepareMaterial(Camera* camera);
		void drawPlayer(Camera* camera);
		void updatePosition(float secondsElapsed, Camera* camera);
};