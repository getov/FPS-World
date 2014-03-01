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

class Application;

class Renderer
{
	private:
		GPUProgram* shader;
		std::vector<IGeometry*> geometries;
		std::vector<GeometryInstance*> geomInstances;

		// take the "global" objects
		Camera* world;
		Light*  gLight;

	public:
		Renderer();
		Renderer(Camera* world, Light* light);
		~Renderer();
		
		void updateScene(float secondsElapsed);

		void prepareSceneObjects();
		void createGeometryInstances();
		void renderGeometries();

		void createBox();
		void createBoxNoTex();
		void removeLastGeometry();
};