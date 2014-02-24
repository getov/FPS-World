#pragma once
#include "IGeometry.h"
#include "GeometryInstance.h"


class GPUProgram;
class Camera;
class Light;
class Box;
class BoxInstance;

class Renderer
{
	private:
		std::vector<BoxInstance*> boxes;
		
		// 
		std::vector<IGeometry*> geometries;
		std::vector<GeometryInstance*> geomInstances;

	public:
		Renderer();
		~Renderer();
		
		void updateScene(float secondsElapsed);

		void prepareSceneObjects();
		void createGeometryInstances();
		void renderGeometries(Camera& world, Light& gLight);

		// DEPRECATED
		void createBoxInstances(Box* box, BoxInstance* boxI);
		void renderBoxInstances(Box* box, Camera* gWorld, Light* gLight);
		void createBox(Box* box, Camera& world, float secElapsed);
};