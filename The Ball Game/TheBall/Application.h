#pragma once

class Player;
class Camera;
class Background;
//
class TestObject;

class Application
{
	private:

		int screenWidth;
		int screenHeight;
		Player* player;
		Camera* camera;
		//Background* bg;

		//
		TestObject* obj;

	public:

		Application();

		~Application();

		void run();

		void initializeScene();

		void updateScene();

		void renderScene();
};