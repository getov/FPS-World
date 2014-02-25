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
#include <string>
#include <sstream>

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
	, appName("FPS World")
	, frameCount(0)
	, lastFrameEnd(0)
	, lastTitleUpdateTime(0)
	, lastTitleUpdateFrameCount(0)
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
	delete gLight;
	delete health;
	delete projectile;
	//delete weapon;
	delete m_renderer;
	delete anBox;
	delete skybox;
	delete gridFloor;

	//delete sun;
}

void Application::initializeScene()
{
	if (!glfwInit())
	{
		std::cerr << "Could not initialize GLFW\n";
	}

	// open a window with GLFW
    glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE); //GLFW_OPENGL_CORE_PROFILE , GLFW_OPENGL_COMPAT_PROFILE
    glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 3);
    glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 2);
    glfwOpenWindowHint(GLFW_WINDOW_NO_RESIZE, GL_TRUE);
    if(!glfwOpenWindow(screenWidth, screenHeight, 8, 8, 8, 8, 16, 0, GLFW_WINDOW)) // for full screen = GLFW_FULLSCREEN
	{
		std::cerr << "glfwOpenWindow failed!\n";
	}
	
	// GLFW settings
    glfwDisable(GLFW_MOUSE_CURSOR);
    glfwSetMousePos(0, 0);
    glfwSetMouseWheel(0);

	glewExperimental = GL_TRUE;
	// initialize GLEW
	if (glewInit() != GLEW_OK)
	{
		std::cerr << "Failed to initialize GLEW\n";
	}

	while(glGetError() != GL_NO_ERROR) {}

	// Enable Depth testing , so that objects that are far away in the distans doesn't overlap closer objects
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	//glEnable(GL_CULL_FACE);
	//glEnable(GL_MULTISAMPLE);
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
	gLight = new Light;
	health = new HealthBar;
	projectile = new Projectile;
	m_renderer = new Renderer;
	weapon = new WeaponModel;
	anBox = new AnotherBox;
	gridFloor = new Grid;
	//sun = new Sphere(10.0, glm::vec4(0.5, 0.7, 0.0, 0.0));

	// setup light
	gLight->setPosition(glm::vec3(0.0, 1.0, 2.0)); // gWorld->cameraPosition() ; glm::vec3(1.0, 0.0, 4.0); glm::vec3(0.0, 1.0, 2.0)
	gLight->setColor(glm::vec3(1, 1, 1)); // white color
	gLight->setAttenuation(0.2f); // 0.2 - light power
	gLight->setAmbiendCoefficient(0.005f);

	// Prepare objects' materials to render
	skybox->prepareMaterial();
	player->prepare(gWorld);
	cross->prepareMaterial();
	//box->prepareMaterial(gWorld);
	health->prepareMaterial();
	//anBox->prepareMaterial(gWorld);
	//m_renderer->createBoxInstances(box, boxI);
	//weapon->prepareMaterial();
	//gridFloor->prepareMaterial();

	//sun->prepareMaterial(*gWorld);

	m_renderer->prepareSceneObjects();
	m_renderer->createGeometryInstances();
}

void Application::renderScene()
{
	glClearColor(0.55f, 0.8f, 0.95f, 0); //skyblue
	//glClearColor(0.0f, 0.0f, 0.0f, 0); //black
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// render world objects
	cross->drawCrosshair();
	health->drawHealthBar();
	//player->renderProjectiles();
	//anBox->drawBox(gWorld, gLight);
	//m_renderer->renderBoxInstances(box, gWorld, gLight);	
	skybox->drawSkybox();
	//weapon->drawWeapon(*gWorld);
	//gridFloor->drawGrid(*gWorld);
	//sun->renderSphere(*gWorld, *gLight);

	m_renderer->renderGeometries(*gWorld, *gLight);

	glfwSwapBuffers();
}

void Application::displayFrameCounter()
{
	++frameCount;

	const unsigned now = glfwGetTime();
	const unsigned frameTime = now - lastFrameEnd;
	const unsigned titleUpdateTimeDelta = now - lastTitleUpdateTime;

	if (titleUpdateTimeDelta > 1)
	{
		const unsigned framesDelta = frameCount - lastTitleUpdateFrameCount;
		const unsigned meanFrameTime = titleUpdateTimeDelta / framesDelta;
		const unsigned fps = framesDelta / titleUpdateTimeDelta;

		std::ostringstream title;
		title << appName << "\t\t\t mean frame time: " << meanFrameTime << " ms || fps: " << fps;
		title.flush();

		glfwSetWindowTitle(title.str().c_str());

		lastTitleUpdateTime = now;
		lastTitleUpdateFrameCount = frameCount;
	}

	lastFrameEnd = glfwGetTime();
}

void Application::handleEvents(float time, Renderer* renderer, Camera* camera)
{
	if (glfwGetMouseButton(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
	{
		renderer->createBox(*camera, time);
	}
	else if (glfwGetMouseButton(GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS)
	{
		renderer->removeLastGeometry();
	}
}

void Application::run()
{
	initializeScene();

	float lastTime = glfwGetTime(); // get time in seconds

	while (glfwGetWindowParam(GLFW_OPENED))
	{
		float thisTime = glfwGetTime();

		player->updatePosition(thisTime - lastTime, gWorld, *skybox);
		//m_renderer->updateScene(thisTime - lastTime);

		handleEvents(thisTime - lastTime, m_renderer, gWorld);

		displayFrameCounter();

		lastTime = thisTime;

		renderScene();
	}
	
	Destroy();

	glfwTerminate();
}