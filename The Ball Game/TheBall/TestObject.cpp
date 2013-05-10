#include <GL\glew.h>
#include <GL\glfw.h>

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

#include "TestObject.h"
#include "GPUProgram.h"
#include "Camera.h"

TestObject::TestObject()
	: shader(nullptr)
	, camera(nullptr)
	, vertexArrayID(0)
{
}

TestObject::~TestObject()
{
	glDeleteBuffers(1, &vertexBuffer);
	glDeleteVertexArrays(1, &vertexArrayID);
	delete camera;
	delete shader;
}

void TestObject::prepareMaterial()
{
	camera = new Camera;

	glGenVertexArrays(1, &vertexArrayID);
	glBindVertexArray(vertexArrayID);

	shader = new GPUProgram;

	shader->loadFragmentShaderFromFile("test.frag");
	shader->loadVertexShaderFromFile("test.vert");

	shader->link();

	static const GLfloat vertexBufferData[] = {
		// horizontal crosshair line one
		-1.0f, -1.0f, 0.0f,	
		-0.3f, -1.0f, 0.0f,

		// horizontal crosshair line two
		 0.3f, -1.0f, 0.0f,
		 1.0f, -1.0f, 0.0f,

		// vertical crosshair line one
		 0.0f, 0.0f, 0.0f,
		 0.0f, -0.7f, 0.0f,

		// horizontal crosshair line two
		 0.0f, -1.3f, 0.0f,
		 0.0f, -2.0f, 0.0f
	};

	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexBufferData), vertexBufferData, GL_STATIC_DRAW);
}

void TestObject::drawObject()
{
	shader->use();

	shader->setUniform("camera", camera->matrix());
	shader->setUniform("model", glm::scale(glm::mat4(), glm::vec3(0.03, 0.03, 0.03)));
	
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glDrawArrays(GL_LINES, 0, 8);
}