#pragma once

class Player;
class Camera;
class Crosshair;
class Box;
class Light;
class HealthBar;
class Projectile;
class Renderer;
class AnotherBox;
class BoxInstance;
class WeaponModel;
class GPUProgram;
class Skybox;
class Grid;
//class Sphere;

class Application
{
	private:

		int screenWidth;
		int screenHeight;
		const char * const appName;

		Player* player;
		Camera* gWorld;
		Crosshair* cross;
		Box* box;
		Light* gLight;
		HealthBar* health;
		Projectile* projectile;
		AnotherBox* anBox;
		BoxInstance* boxI;
		Renderer* m_renderer;
		WeaponModel* weapon;
		Skybox* skybox;
		Grid* gridFloor;

		//Sphere* sun;

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