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
		AnotherBox* anBox;
		BoxInstance* boxI;
		Renderer* m_renderer;
		WeaponModel* weapon;

		Application();
		~Application();

		void Destroy();

	public:

		static Application& Instance();

		void run();

		void initializeScene();

		void updateScene();

		void renderScene();
};