#include <GL\glew.h>
#include <GL\glfw.h>

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

#include "Player.h"
#include "GPUProgram.h"
#include "Camera.h"
#include "Projectile.h"
#include "Skybox.h"

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
	// free the allocated memory for ammo
	for (auto i = ammo.begin(); i != ammo.end(); ++i)
	{
		delete (*i);
	}
}

void Player::prepare(Camera* camera)
{
	camera->setCameraPosition(glm::vec3(0.0f, -0.10f, 4.0f));	
	camera->setViewportAspectRatio(1366 / 768);
	// set the "look at" camera position, but it gets reseted as soon as mouse coordinates are registered
	//camera->offsetOrientation(0.0f, 0.0f);

	// TO FIX *********
	for (int i = 0; i < 2; ++i)
	{
		ammo.push_back(new Projectile);
	}

	for (auto i = ammo.begin(); i != ammo.end(); ++i)
	{
		(*i)->prepareMaterial();
	}
	// ***********************
}

void Player::updatePosition(float secondsElapsed, Camera* camera, Skybox& cubemap)
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

	// Hold left SHIFT for slow movement
	if (glfwGetKey(GLFW_KEY_LSHIFT) == GLFW_PRESS)
	{
		moveSpeed = 0.1;
	}
	else if (glfwGetKey(GLFW_KEY_LSHIFT) == GLFW_RELEASE && glfwGetKey(GLFW_KEY_LALT) == GLFW_RELEASE)
	{
		moveSpeed = 0.5;
	}
	
	// Hold left ALT for sprint
	if (glfwGetKey(GLFW_KEY_LALT) == GLFW_PRESS)
	{
		moveSpeed = 1.0;
	}
	else if (glfwGetKey(GLFW_KEY_LALT) == GLFW_RELEASE && glfwGetKey(GLFW_KEY_LSHIFT) == GLFW_RELEASE)
	{
		moveSpeed = 0.5;
	}

	// exit game
	if (glfwGetKey(GLFW_KEY_ESC) == GLFW_PRESS)
	{
		glfwTerminate();
	}

	glfwGetMousePos(&mouseX, &mouseY);
	camera->offsetOrientation(mouseSensitivity * mouseY, mouseSensitivity * mouseX);
	cubemap.getSkyboxCamera()->offsetOrientation(mouseSensitivity * mouseY, mouseSensitivity * mouseX);

	// TO FIX *********
	if (glfwGetMouseButton(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
	{
		mouseLeftClick = true;
	}

	upAngle = mouseSensitivity * mouseY;
	rightAngle = mouseSensitivity * mouseX;


	if (mouseLeftClick)
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