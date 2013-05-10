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
	, camera(nullptr)
	, vertexArrayID(0)
	, moveSpeed(1.0)
{
}

Player::~Player()
{
	glDeleteBuffers(1, &vertexBuffer);
	glDeleteVertexArrays(1, &vertexArrayID);
	delete camera;
	delete shader;
}

void Player::prepareMaterial()
{
	camera = new Camera;

	glGenVertexArrays(1, &vertexArrayID);
	glBindVertexArray(vertexArrayID);

	shader = new GPUProgram;

	shader->loadFragmentShaderFromFile("playerFrag.frag");
	shader->loadVertexShaderFromFile("playerVert.vert");

	shader->link();

	static const GLfloat vertexBufferData[] = {
		/*-1.0f, -1.0f, 0.0f,	
		 1.0f, -1.0f, 0.0f,
		 0.0f, 1.0f, 0.0f*/
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

	/*camera->setCameraPosition(glm::vec3(0, 0, 0));
	camera->setViewportAspectRatio(1366 / 768);*/
}

void Player::drawPlayer()
{
	shader->use();

	shader->setUniform("camera", camera->matrix());
	shader->setUniform("model", glm::scale(glm::mat4(), glm::vec3(0.03, 0.03, 0.03)));

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glDrawArrays(GL_TRIANGLES, 0, 36);
	glDrawArrays(GL_TRIANGLES, 0, 36);
}

void Player::updatePosition(float secondsElapsed)
{
	const GLfloat degreesPerSecond = 180.0f;

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
		camera->offsetCameraPosition(secondsElapsed * moveSpeed * camera->right());
	}

	if (glfwGetKey('D'))
	{
		camera->offsetCameraPosition(secondsElapsed * moveSpeed * -camera->right());
	}
}