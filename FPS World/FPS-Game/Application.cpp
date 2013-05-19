#include <GL\glew.h>
#include <GL\glfw.h>

#include <iostream>

#include "Application.h"
#include "Player.h"
#include "GPUProgram.h"
#include "Camera.h"
#include "Crosshair.h"
#include "Box.h"
#include "Light.h"
#include "HealthBar.h"
#include "Projectile.h"
//
#include "AnotherBox.h"

Application::Application()
	: screenHeight(768)
	, screenWidth(1366)
{
}

Application::~Application()
{
	delete player;
	delete gWorld;
	delete cross;
	delete box;
	delete gLight;
	delete health;
	delete projectile;
	//
	delete anBox;
}

void Application::initializeScene()
{
	if (!glfwInit())
	{
		std::cerr << "Could not initialize GLFW\n";
	}

	// open a window with GLFW
    glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 3);
    glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 2);
    glfwOpenWindowHint(GLFW_WINDOW_NO_RESIZE, GL_TRUE);
    if(!glfwOpenWindow(screenWidth, screenHeight, 8, 8, 8, 8, 16, 0, GLFW_WINDOW))
	{
		std::cerr << "glfwOpenWindow failed!\n";
	}

	// initialize GLEW
	if (glewInit() != GLEW_OK)
	{
		std::cerr << "Failed to initialize GLEW\n";
	}

	while(glGetError() != GL_NO_ERROR) {}

	// Enable Depth testing , so that objects that are far away in the distans doesn't overlap closer objects
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glfwDisable(GLFW_MOUSE_CURSOR);

	/* 
		Initialize game objects here instead in the constructor
		Memory usage highly decreased 
	*/
	player = new Player;
	gWorld = new Camera;
	cross = new Crosshair;
	box = new Box;
	gLight = new Light;
	health = new HealthBar;
	projectile = new Projectile;
	//
	anBox = new AnotherBox;

	// setup light
	gLight->setPosition(gWorld->cameraPosition());
	gLight->setColor(glm::vec3(1,1,1)); // white color

	player->prepare(gWorld);

	// Prepare objects' materials to render
	cross->prepareMaterial();
	box->prepareMaterial(gWorld);
	health->prepareMaterial();
	//projectile->prepareMaterial();
	//
	anBox->prepareMaterial(gWorld);
}

void Application::renderScene()
{
	glClearColor(0.55f, 0.8f, 0.95f, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// render world objects
	cross->drawCrosshair();
	box->drawBox(gWorld, gLight);
	health->drawHealthBar();
	//projectile->drawProjectile();
	player->renderProjectiles();
	//
	anBox->drawBox(gWorld);

	glfwSwapBuffers();
}

void Application::run()
{
	initializeScene();

	double lastTime = glfwGetTime();

	while (glfwGetWindowParam(GLFW_OPENED))
	{
		double thisTime = glfwGetTime();

		player->updatePosition(thisTime - lastTime, gWorld);
		//projectile->updatePosition(thisTime - lastTime);

		lastTime = thisTime;

		renderScene();
	}

	glfwTerminate();
}