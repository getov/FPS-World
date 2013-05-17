#include <GL\glew.h>
#include <GL\glfw.h>

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

#include "Player.h"
#include "GPUProgram.h"
#include "Camera.h"

#include <iostream>

Player::Player()
	: shader(nullptr)
	, vertexArrayID(0)
	, moveSpeed(0.1)
	, degreesPerSecond(180)
	, mouseSensitivity(0.1)
{
}

Player::~Player()
{
	glDeleteBuffers(1, &vertexBuffer);
	glDeleteVertexArrays(1, &vertexArrayID);
	delete shader;
}

void Player::prepareMaterial(Camera* camera)
{
	glGenVertexArrays(1, &vertexArrayID);
	glBindVertexArray(vertexArrayID);

	shader = new GPUProgram;

	shader->loadFragmentShaderFromFile("playerFrag.frag");
	shader->loadVertexShaderFromFile("playerVert.vert");

	shader->link();

	static const GLfloat vertexBufferData[] = {
	
		// bottom
        -1.0f,-1.0f,-1.0f,  // 0.0f, 0.0f,
         1.0f,-1.0f,-1.0f,  // 1.0f, 0.0f,
        -1.0f,-1.0f, 1.0f,  // 0.0f, 1.0f,
         1.0f,-1.0f,-1.0f,  // 1.0f, 0.0f,
         1.0f,-1.0f, 1.0f,  // 1.0f, 1.0f,
        -1.0f,-1.0f, 1.0f,  // 0.0f, 1.0f,

        // top
        -1.0f, 1.0f,-1.0f, //  0.0f, 0.0f,
        -1.0f, 1.0f, 1.0f, //  0.0f, 1.0f,
         1.0f, 1.0f,-1.0f, //  1.0f, 0.0f,
         1.0f, 1.0f,-1.0f,  // 1.0f, 0.0f,
        -1.0f, 1.0f, 1.0f,//   0.0f, 1.0f,
         1.0f, 1.0f, 1.0f,  // 1.0f, 1.0f,

        // front
        -1.0f,-1.0f, 1.0f,  // 1.0f, 0.0f,
         1.0f,-1.0f, 1.0f,  // 0.0f, 0.0f,
        -1.0f, 1.0f, 1.0f,  // 1.0f, 1.0f,
         1.0f,-1.0f, 1.0f,   //0.0f, 0.0f,
         1.0f, 1.0f, 1.0f,   //0.0f, 1.0f,
        -1.0f, 1.0f, 1.0f,   //1.0f, 1.0f,

        // back
        -1.0f,-1.0f,-1.0f,  // 0.0f, 0.0f,
        -1.0f, 1.0f,-1.0f,  // 0.0f, 1.0f,
         1.0f,-1.0f,-1.0f,  // 1.0f, 0.0f,
         1.0f,-1.0f,-1.0f, //  1.0f, 0.0f,
        -1.0f, 1.0f,-1.0f,  // 0.0f, 1.0f,
         1.0f, 1.0f,-1.0f,   //1.0f, 1.0f,

        // left
        -1.0f,-1.0f, 1.0f,   //0.0f, 1.0f,
        -1.0f, 1.0f,-1.0f,  // 1.0f, 0.0f,
        -1.0f,-1.0f,-1.0f,  // 0.0f, 0.0f,
        -1.0f,-1.0f, 1.0f,  // 0.0f, 1.0f,
        -1.0f, 1.0f, 1.0f,   //1.0f, 1.0f,
        -1.0f, 1.0f,-1.0f,   //1.0f, 0.0f,

        // right
         1.0f,-1.0f, 1.0f,   //1.0f, 1.0f,
         1.0f,-1.0f,-1.0f,   //1.0f, 0.0f,
         1.0f, 1.0f,-1.0f,   //0.0f, 0.0f,
         1.0f,-1.0f, 1.0f,   //1.0f, 1.0f,
         1.0f, 1.0f,-1.0f,  // 0.0f, 0.0f,
         1.0f, 1.0f, 1.0f,   //0.0f, 1.0f
	};

	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexBufferData), vertexBufferData, GL_STATIC_DRAW);

	camera->setCameraPosition(glm::vec3(0, 0, 0));
	camera->setViewportAspectRatio(1366 / 768);
	//glm::lookAt(glm::vec3(0,0,1), glm::vec3(-1,0,0), glm::vec3(0,1,0));
}

void Player::drawPlayer(Camera* camera)
{
	shader->use();

	shader->setUniform("camera", camera->matrix());
	shader->setUniform("model", glm::scale(glm::mat4(), glm::vec3(0.15, 0.15, 0.15)));

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glDrawArrays(GL_TRIANGLES, 0, 36);
	glDrawArrays(GL_TRIANGLES, 0, 36);

	//shader->stopUsing();
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

	// cursor stays inside the window and the camera doesn't freak out ;)
	glfwSetMousePos(0, 0);
}