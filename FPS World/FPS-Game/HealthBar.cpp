#include <GL\glew.h>
#include <GL\glfw.h>

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

#include "GPUProgram.h"
#include "HealthBar.h"

HealthBar::HealthBar()
	: shader(nullptr)
	, vertexArrayID(0)
	, m_color(0.0, 1.0, 0.0)
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

	shader->loadFragmentShaderFromFile("SimpleColor.frag");
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

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	// unbind VBO and VAO
	glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void HealthBar::drawHealthBar()
{
	shader->use();

	shader->setUniform("model", transform);
	shader->setUniform("m_color", m_color);

	glBindVertexArray(vertexArrayID);
	glDrawArrays(GL_TRIANGLES, 0, 6);

	// unbind
	glBindVertexArray(0);
	shader->stopUsing();
}