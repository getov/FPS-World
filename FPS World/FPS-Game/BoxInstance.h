#pragma once

class Box;

class BoxInstance
{
	public:
		BoxInstance();

		Box* asset;
		glm::mat4 transform;
};