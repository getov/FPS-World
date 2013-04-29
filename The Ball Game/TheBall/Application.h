#pragma once

class Player;

class Application
{
	private:

		int screenWidth;
		int screenHeight;
		Player* player;

	public:

		Application();

		~Application();

		void run();

		void initializeScene();

		void updateScene();

		void renderScene();
};