#pragma once
#include <vector>

class GPUProgram;
class Camera;

class Skybox;

class Player
{
	private:
		GLfloat degreesPerSecond;
		GLfloat degreesRotated;
		float moveSpeed;
		float mouseSensitivity;
		int mouseX;
		int mouseY;

		float upAngle;
		float rightAngle;

		//Skybox* skybox;

	public:
		Player();
		~Player();

		void prepare(Camera* camera);
		void updatePosition(float secondsElapsed, Camera* camera, Skybox& cubemap);
};