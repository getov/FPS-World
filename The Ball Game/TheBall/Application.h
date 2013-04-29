#pragma once

class Player;
class Camera;
//
class TestObject;

class Application
{
	private:

		int screenWidth;
		int screenHeight;
		Player* player;
		Camera* camera;
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