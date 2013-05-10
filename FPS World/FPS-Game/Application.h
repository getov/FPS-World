#pragma once

class Player;
class Camera;
class Background;
//
class Crosshair;

class Application
{
	private:

		int screenWidth;
		int screenHeight;
		Player* player;
		Camera* camera;
		//Background* bg;

		//
		Crosshair* cross;

	public:

		Application();

		~Application();

		void run();

		void initializeScene();

		void updateScene();

		void renderScene();
};