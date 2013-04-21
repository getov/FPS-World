#pragma once

class Application
{
	private:

		int screenWidth;
		int screenHeight;

	public:

		Application();

		void run();

		void initializeScene();

		void updateScene();

		void renderScene();
};