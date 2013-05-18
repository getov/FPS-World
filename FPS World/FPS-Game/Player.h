#pragma once

class GPUProgram;
class Camera;

class Player
{
	private:
		GLfloat degreesPerSecond;
		GLfloat degreesRotated;
		float moveSpeed;
		float mouseSensitivity;
		int mouseX;
		int mouseY;

	public:
		Player();
		~Player();

		void prepare(Camera* camera);
		void updatePosition(float secondsElapsed, Camera* camera);
};