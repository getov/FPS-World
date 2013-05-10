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

		GLfloat degreesPerSecond;
		GLfloat degreesRotated;
		float moveSpeed;
		float mouseSensitivity;
		int mouseX;
		int mouseY;

	public:
		Player();
		~Player();

		void prepareMaterial();
		void drawPlayer();
		void updatePosition(float secondsElapsed);

		// TODO: Think how to make Global World Camera
		//static Camera* getWorldCamera();
};