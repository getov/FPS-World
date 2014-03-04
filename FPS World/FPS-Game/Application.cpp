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
#include "Renderer.h"
#include "WeaponModel.h"
#include "Skybox.h"


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
	skybox = new Skybox;
	player = new Player;
	gWorld = new Camera;
	cross  = new Crosshair;
	gLight = new Light(glm::vec3(1.0, 1.0, 1.0), glm::vec3(0.0, 2.0, 4.0), 0.2f, 0.005f);
	health = new HealthBar;
	//weapon = new WeaponModel;

	m_renderer = new Renderer(gWorld, gLight);
	m_eventController = new EventHandler(m_renderer);
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
	//delete weapon;
	delete m_renderer;
	delete skybox;

	delete m_eventController;
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

	glEnable(GL_CULL_FACE);

	// Prepare objects' materials to render
	skybox->prepareMaterial();
	player->prepare(gWorld);
	cross->prepareMaterial();
	health->prepareMaterial();
	//weapon->prepareMaterial();

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
	skybox->drawSkybox();
	//weapon->drawWeapon(*gWorld);

	m_renderer->renderGeometries();

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

void Application::run()
{
	initializeScene();

	float lastTime = glfwGetTime(); // get time in seconds

	while (glfwGetWindowParam(GLFW_OPENED))
	{
		float thisTime = glfwGetTime();

		player->updatePosition(thisTime - lastTime, gWorld, *skybox);
		m_renderer->updateScene(thisTime - lastTime);

		m_eventController->handleEvents();

		displayFrameCounter();

		lastTime = thisTime;

		renderScene();
	}
	
	Destroy();

	glfwTerminate();
}