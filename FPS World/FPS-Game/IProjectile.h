#pragma once

#include "IGeometry.h"

class IProjectile : public IGeometry
{
public:
	virtual ~IProjectile() {}

	virtual void shoot() = 0;
};