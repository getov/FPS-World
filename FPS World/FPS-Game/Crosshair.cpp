#include <GL\glew.h>
#include <GL\glfw.h>

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

#include "Crosshair.h"
#include "GPUProgram.h"
#include "Camera.h"

Crosshair::Crosshair()
	: shader(nullptr)
	, camera(nullptr)
	, vertexArrayID(0)
{
}

Crosshair::~Crosshair()
{
	glDeleteBuffers(1, &vertexBuffer);
	glDeleteVertexArrays(1, &vertexArrayID);
	delete camera;
	delete shader;
}

void Crosshair::prepareMaterial()
{
	camera = new Camera;

	glGenVertexArrays(1, &vertexArrayID);
	glBindVertexArray(vertexArrayID);

	shader = new GPUProgram;

	shader->loadFragmentShaderFromFile("crosshair.frag");
	shader->loadVertexShaderFromFile("crosshair.vert");

	shader->link();

	GLfloat vertexBufferData[] = {
        //  X     Y     Z
		// horizontal crosshair left line
		-0.01f, 0.1f, 0.0f,
		 0.02f, 0.1f, 0.0f,

		 // horizontal crosshair right line
		 0.04f, 0.1f, 0.0f,
		 0.07f, 0.1f, 0.0f,

		 // vertical crosshair top line
		 0.03f, 0.16f, 0.0f,
		 0.03f, 0.11f, 0.0f,

		 // vertical crosshair bottom line
		 0.03f, 0.09f, 0.0f,
		 0.03f, 0.04f, 0.0f
    };

	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexBufferData), vertexBufferData, GL_STATIC_DRAW);

	// scale the size of the crosshair
	transform = glm::scale(glm::mat4(), glm::vec3(1.0, 1.0, 1.0));
}

void Crosshair::drawCrosshair()
{
	shader->use();

	shader->setUniform("model", transform);
	
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glDrawArrays(GL_LINES, 0, 8);
}