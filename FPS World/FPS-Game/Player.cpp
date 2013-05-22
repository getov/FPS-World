#include <GL\glew.h>
#include <GL\glfw.h>

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

#include "Player.h"
#include "GPUProgram.h"
#include "Camera.h"
#include "Projectile.h"

#include <iostream>
#include <vector>

Player::Player()
	: moveSpeed(0.5)
	, degreesPerSecond(180)
	, mouseSensitivity(0.1)
{
}

Player::~Player()
{
	
}

void Player::prepare(Camera* camera)
{
	camera->setCameraPosition(glm::vec3(0, 0, 0));	
	camera->setViewportAspectRatio(1366 / 768);
	// set the "look at" camera position, but it gets reseted as soon as mouse coordinates are registered
	camera->offsetOrientation(-30.0f, 20.0f);

	// TO FIX *********
	for (int i = 0; i < 1; ++i)
	{
		ammo.push_back(new Projectile);
	}

	for (auto i = ammo.begin(); i != ammo.end(); ++i)
	{
		(*i)->prepareMaterial();
	}
	// ***********************
}

void Player::updatePosition(float secondsElapsed, Camera* camera)
{
	if (glfwGetKey('S'))
	{
		camera->offsetCameraPosition(secondsElapsed * moveSpeed * -camera->forward());
	}

	if (glfwGetKey('W'))
	{
		camera->offsetCameraPosition(secondsElapsed * moveSpeed * camera->forward());
	}

	if (glfwGetKey('A'))
	{
		camera->offsetCameraPosition(secondsElapsed * moveSpeed * -camera->right());
	}

	if (glfwGetKey('D'))
	{
		camera->offsetCameraPosition(secondsElapsed * moveSpeed * camera->right());
	}

	glfwGetMousePos(&mouseX, &mouseY);
	camera->offsetOrientation(mouseSensitivity * mouseY, mouseSensitivity * mouseX);

	// TO FIX *********
	if (glfwGetMouseButton(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
	{
		mouseLeftClick = true;

		//ammo.push_back(new Projectile);
		upAngle = mouseSensitivity * mouseY;
		rightAngle = mouseSensitivity * mouseX;
	}

	if (fireDelay > 0)
	{
		--fireDelay;
	}

	if (mouseLeftClick && fireDelay == 0)
	{
		for (auto i = ammo.begin(); i != ammo.end(); ++i)
		{
			(*i)->updatePosition(secondsElapsed, upAngle, rightAngle);
		}
	}

	// **************************

	// cursor stays inside the window and the camera doesn't freak out ;)
	glfwSetMousePos(0, 0);
}

void Player::renderProjectiles()
{
	for (auto i = ammo.begin(); i != ammo.end(); ++i)
	{
		if (mouseLeftClick)
		{
			(*i)->drawProjectile();
		}
	}
}

// states
bool Player::mouseLeftClick = false;
float Player::fireDelay = 5.0;