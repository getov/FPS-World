#pragma once

class Player;
class Camera;
class Crosshair;
class Box;
class Light;
class HealthBar;
class Projectile;
//
class AnotherBox;

class Application
{
	private:

		int screenWidth;
		int screenHeight;
		Player* player;
		Camera* gWorld;
		Crosshair* cross;
		Box* box;
		Light* gLight;
		HealthBar* health;
		Projectile* projectile;
		//
		AnotherBox* anBox;

	public:

		Application();

		~Application();

		void run();

		void initializeScene();

		void updateScene();

		void renderScene();
};