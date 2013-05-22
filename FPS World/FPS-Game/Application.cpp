#include <GL\glew.h>
#include <GL\glfw.h>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

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
//
#include "AnotherBox.h"
#include "BoxInstance.h"

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
	m_renderer = new Renderer;
	//
	anBox = new AnotherBox;

	// setup light
	gLight->setPosition(gWorld->cameraPosition());
	gLight->setColor(glm::vec3(1,1,1)); // white color

	// Prepare objects' materials to render
	player->prepare(gWorld);
	cross->prepareMaterial();
	box->prepareMaterial(gWorld);
	health->prepareMaterial();
	anBox->prepareMaterial(gWorld);
	m_renderer->createBoxInstances(box, boxI);
}

void Application::renderScene()
{
	glClearColor(0.55f, 0.8f, 0.95f, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// render world objects
	cross->drawCrosshair();
	health->drawHealthBar();
	player->renderProjectiles();
	anBox->drawBox(gWorld);
	m_renderer->renderBoxInstances(box, gWorld, gLight);

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

//void Application::createBoxInstance()
//{
//	boxI = new BoxInstance;
//	boxI->asset = box;
//	boxI->transform = glm::translate(glm::mat4(), glm::vec3(-1, 0, 0)) * glm::scale(glm::mat4(), glm::vec3(0.30, 0.30, 0.30));
//	boxes.push_back(boxI);
//
//	boxI = new BoxInstance;
//	boxI->asset = box;
//	boxI->transform = glm::translate(glm::mat4(), glm::vec3(-2, 0, 0)) * glm::scale(glm::mat4(), glm::vec3(0.30, 0.30, 0.30));
//	boxes.push_back(boxI);
//}
//
//void Application::renderBoxInstance(BoxInstance* boxI)
//{
//	box = boxI->asset;
//	GPUProgram* shader = box->getShader();
//
//	shader->use();
//	shader->setUniform("camera", gWorld->matrix());
//	shader->setUniform("model", boxI->transform);
//
//	glEnableVertexAttribArray(0);
//	glBindBuffer(GL_ARRAY_BUFFER, box->getVAO());
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8*sizeof(GLfloat), NULL);
//
//	// connect the normal to the "vertNormal" attribute of the vertex shader
//	glEnableVertexAttribArray(1);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_TRUE, 8*sizeof(GLfloat), (const GLvoid*)(5 * sizeof(GLfloat)));
//
//	shader->setUniform("light.position", gLight->getPosition());
//	shader->setUniform("light.intensities", gLight->getColor());
//
//    glDrawArrays(GL_TRIANGLES, 0, 36);
//}