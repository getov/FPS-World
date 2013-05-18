#include <GL\glew.h>
#include <GL\glfw.h>

#include <iostream>

#include "Application.h"
#include "Player.h"
#include "GPUProgram.h"
#include "Camera.h"
#include "Crosshair.h"
#include "Box.h"
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
	//
	anBox = new AnotherBox;

	player->prepare(gWorld);
	// Prepare objects' materials to render
	cross->prepareMaterial();
	box->prepareMaterial(gWorld);
	//
	anBox->prepareMaterial(gWorld);
}

void Application::renderScene()
{
	glClearColor(0.55f, 0.8f, 0.95f, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	cross->drawCrosshair();
	box->drawBox(gWorld);
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

		lastTime = thisTime;

		renderScene();
	}

	glfwTerminate();
}