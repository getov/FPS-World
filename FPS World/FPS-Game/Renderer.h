#pragma once

class GPUProgram;
class Camera;
class Light;
class Box;
class BoxInstance;

class Renderer
{
	private:
		std::vector<BoxInstance*> boxes;

	public:
		Renderer();
		~Renderer();

		void createBoxInstances(Box* box, BoxInstance* boxI);
		void renderBoxInstances(Box* box, Camera* gWorld, Light* gLight);
		void updateScene(float secondsElapsed);
};