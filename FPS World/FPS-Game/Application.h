#pragma once

class Player;
class Camera;
class Crosshair;
class Light;
class HealthBar;
class Renderer;
class WeaponModel;
class GPUProgram;
class Skybox;

#include "IGeometry.h"
#include "EventHandler.h"

class Application
{
	private:

		int screenWidth;
		int screenHeight;
		const char * const appName;

		// UI		
		Crosshair* cross;
		HealthBar* health;

		// Objects
		Player*      player;
		Camera*      gWorld;
		Light*       gLight;
		WeaponModel* weapon;
		Skybox*      skybox;

		// Handlers
		Renderer*     m_renderer;
		EventHandler* m_eventController;

		Application();
		Application(const Application&);
		void operator=(const Application&);
		~Application();

		void Destroy();

		void initializeScene();

		void renderScene();

		//fps stuff
		unsigned frameCount;
		unsigned lastFrameEnd;
		unsigned lastTitleUpdateTime;
		unsigned lastTitleUpdateFrameCount;

		//* Function that calculates and displays
		//* frame time and fps on the window frame
		void displayFrameCounter();

	public:

		static Application& Instance();

		void run();
};