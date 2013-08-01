#include <GL\glew.h>
#include <GL\glfw.h>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

#include <assimp\Importer.hpp>
#include <assimp\cimport.h>
#include <assimp\scene.h>
#include <assimp\postprocess.h>

#include <iostream>
#include <vector>

#include "Application.h"
#include "Player.h"
#include "GPUProgram.h"
#include "Camera.h"
#include "Crosshair.h"
#include "Box.h"
#include "Light.h"
#include "HealthBar.h"
#include "Projectile.h"
#include "Renderer.h"
#include "WeaponModel.h"
#include "Skybox.h"
#include "Grid.h"
//
#include "AnotherBox.h"
#include "BoxInstance.h"

Application& Application::Instance()
{
	static Application app;

	return app;
}

Application::Application()
	: screenWidth(1366)
	, screenHeight(768)
{
}

Application::~Application()
{
}

void Application::Destroy()
{
	delete player;
	delete gWorld;
	delete cross;
	delete box;
	delete gLight;
	delete health;
	delete projectile;
	delete weapon;
	delete m_renderer;
	//
	delete anBox;
	delete skybox;
	delete gridFloor;
}

void Application::initializeScene()
{
	if (!glfwInit())
	{
		std::cerr << "Could not initialize GLFW\n";
	}

	// open a window with GLFW
    glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
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
	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	/* 
		Initialize game objects here instead in the constructor
		Memory usage highly decreased 
	*/
	skybox = new Skybox;
	player = new Player;
	gWorld = new Camera;
	cross = new Crosshair;
	box = new Box;
	gLight = new Light;
	health = new HealthBar;
	projectile = new Projectile;
	m_renderer = new Renderer;
	weapon = new WeaponModel;
	//
	anBox = new AnotherBox;
	gridFloor = new Grid;

	// setup light
	gLight->setPosition(gWorld->cameraPosition());
	gLight->setColor(glm::vec3(1, 1, 1)); // white color
	gLight->setAttenuation(0.2f);
	gLight->setAmbiendCoefficient(0.005f);

	// Prepare objects' materials to render
	skybox->prepareMaterial();
	player->prepare(gWorld);
	cross->prepareMaterial();
	box->prepareMaterial(gWorld);
	health->prepareMaterial();
	anBox->prepareMaterial(gWorld);
	m_renderer->createBoxInstances(box, boxI);
	//
	weapon->prepareMaterial();
	gridFloor->prepareMaterial();
}

void Application::renderScene()
{
	glClearColor(0.55f, 0.8f, 0.95f, 0); //skyblue
	//glClearColor(0.0f, 0.0f, 0.0f, 0); //black
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// render world objects
	cross->drawCrosshair();
	health->drawHealthBar();
	player->renderProjectiles();
	anBox->drawBox(gWorld);
	m_renderer->renderBoxInstances(box, gWorld, gLight);
	//
	weapon->drawWeapon();
	skybox->drawSkybox(*gWorld);
	gridFloor->drawGrid(*gWorld);

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

	Destroy();

	glfwTerminate();
}