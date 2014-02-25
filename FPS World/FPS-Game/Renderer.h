#pragma once
#include "IGeometry.h"
#include "GeometryInstance.h"
#include "GPUProgram.h"
#include "Camera.h"
#include "Light.h"
#include "Box.h"
#include "Util.h"
#include "Texture.h"

#include <vector>
#include <algorithm>
//class GPUProgram;
//class Camera;
//class Light;
//class Box;

class Renderer
{
	private:
		GPUProgram* shader;
		std::vector<IGeometry*> geometries;
		std::vector<GeometryInstance*> geomInstances;

	public:
		Renderer();
		~Renderer();
		
		void updateScene(float secondsElapsed);

		void prepareSceneObjects();
		void createGeometryInstances();
		void renderGeometries(Camera& world, Light& gLight);

		void createBox(Camera& world, float secElapsed);
		void removeLastGeometry();
};