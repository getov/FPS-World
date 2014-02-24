#pragma once

#include "IGeometry.h"

class GeometryInstance
{
public:
	GeometryInstance();

	IGeometry* asset;
	glm::mat4 transform;
};