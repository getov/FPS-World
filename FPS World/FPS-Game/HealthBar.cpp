#include <GL\glew.h>
#include <GL\glfw.h>

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

#include "GPUProgram.h"
#include "HealthBar.h"

HealthBar::HealthBar()
	: shader(nullptr)
	, vertexArrayID(0)
{
}

HealthBar::~HealthBar()
{
	glDeleteBuffers(1, &vertexBuffer);
	glDeleteVertexArrays(1, &vertexArrayID);
	delete shader;
}

void HealthBar::prepareMaterial()
{
	glGenVertexArrays(1, &vertexArrayID);
	glBindVertexArray(vertexArrayID);

	shader = new GPUProgram;

	shader->loadFragmentShaderFromFile("lostHP.frag");
	shader->loadVertexShaderFromFile("lostHP.vert");

	shader->link();

	GLfloat vertexBufferData[] = {

		0.01, 0.10, 0.0,
		0.01, 0.20, 0.0,
		0.20, 0.20, 0.0,

		0.01, 0.10, 0.0,
		0.20, 0.20, 0.0,
		0.20, 0.10, 0.0
	};

	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexBufferData), vertexBufferData, GL_STATIC_DRAW);

	// transform and translate Healthbar to the lower left corner
	transform = glm::translate(glm::mat4(), glm::vec3(-1, -1, 0)) * glm::scale(glm::mat4(), glm::vec3(2.0, 0.5, 0.0));
}

void HealthBar::drawHealthBar()
{
	shader->use();

	shader->setUniform("model", transform);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glDrawArrays(GL_TRIANGLES, 0, 6);
}