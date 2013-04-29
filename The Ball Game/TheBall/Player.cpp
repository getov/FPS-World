#include <GL\glew.h>
#include <GL\glfw.h>

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

#include "Player.h"
#include "GPUProgram.h"
#include "Camera.h"

Player::Player()
	: shader(nullptr)
	, camera(nullptr)
	, vertexArrayID(0)
{
}

Player::~Player()
{
	glDeleteBuffers(1, &vertexBuffer);
	glDeleteVertexArrays(1, &vertexArrayID);
}

void Player::prepare()
{
	camera = new Camera;

	glGenVertexArrays(1, &vertexArrayID);
	glBindVertexArray(vertexArrayID);

	shader = new GPUProgram;

	shader->loadFragmentShaderFromFile("playerFrag.frag");
	shader->loadVertexShaderFromFile("playerVert.vert");

	shader->link();

	static const GLfloat vertexBufferData[] = {
		-1.0f, -1.0f, 0.0f,	
		 1.0f, -1.0f, 0.0f,
		 0.0f, 1.0f, 0.0f
	};

	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexBufferData), vertexBufferData, GL_STATIC_DRAW);

	delete camera;
	delete shader;
}

void Player::drawPlayer()
{
	camera = new Camera;
	shader = new GPUProgram;

	shader->use();

	shader->setUniform("camera", camera->matrix());
	shader->setUniform("model", glm::scale(glm::mat4(), glm::vec3(0, 0, 0)));

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	delete camera;
	delete shader;
}