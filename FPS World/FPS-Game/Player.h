#pragma once
#include <vector>

class GPUProgram;
class Camera;
class Projectile;

class Player
{
	private:
		GLfloat degreesPerSecond;
		GLfloat degreesRotated;
		float moveSpeed;
		float mouseSensitivity;
		int mouseX;
		int mouseY;

		std::vector<Projectile*> ammo;
		float upAngle;
		float rightAngle;

	public:
		Player();
		~Player();

		void prepare(Camera* camera);
		void updatePosition(float secondsElapsed, Camera* camera);
		void renderProjectiles();

		//states
		static bool mouseLeftClick;
		static float fireDelay;
};