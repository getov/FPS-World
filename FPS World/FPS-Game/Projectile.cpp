#include <GL\glew.h>
#include <GL\glfw.h>

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

#include "GPUProgram.h"
#include "Camera.h"
#include "Projectile.h"
#include "Player.h"

Projectile::Projectile()
	: shader(nullptr)
	, camera(nullptr)
	, vertexArrayID(0)
	, moveSpeed(5.0)
	, m_color(0.5, 0.0, 0.7)
{
}

Projectile::~Projectile()
{
	glDeleteBuffers(1, &vertexBuffer);
	glDeleteVertexArrays(1, &vertexArrayID);
	delete camera;
	delete shader;
}

void Projectile::prepareMaterial()
{
	camera = new Camera;

	glGenVertexArrays(1, &vertexArrayID);
	glBindVertexArray(vertexArrayID);

	shader = new GPUProgram;

	shader->loadFragmentShaderFromFile("SimpleColor.frag");
	shader->loadVertexShaderFromFile("projectile.vert");

	shader->link();

	static const GLfloat vertexBufferData[] = {
		 //  X     Y     Z       U     V          Normal
        // bottom
        -1.0f,-1.0f,-1.0f,   //0.0f, 0.0f,   0.0f, -1.0f, 0.0f,
         1.0f,-1.0f,-1.0f,   //1.0f, 0.0f,   0.0f, -1.0f, 0.0f,
        -1.0f,-1.0f, 1.0f,   //0.0f, 1.0f,   0.0f, -1.0f, 0.0f,
         1.0f,-1.0f,-1.0f,   //1.0f, 0.0f,   0.0f, -1.0f, 0.0f,
         1.0f,-1.0f, 1.0f,   //1.0f, 1.0f,   0.0f, -1.0f, 0.0f,
        -1.0f,-1.0f, 1.0f,   //0.0f, 1.0f,   0.0f, -1.0f, 0.0f,

        // top
        -1.0f, 1.0f,-1.0f,   //0.0f, 0.0f,   0.0f, 1.0f, 0.0f,
        -1.0f, 1.0f, 1.0f,   //0.0f, 1.0f,   0.0f, 1.0f, 0.0f,
         1.0f, 1.0f,-1.0f,   //1.0f, 0.0f,   0.0f, 1.0f, 0.0f,
         1.0f, 1.0f,-1.0f,   //1.0f, 0.0f,   0.0f, 1.0f, 0.0f,
        -1.0f, 1.0f, 1.0f,   //0.0f, 1.0f,   0.0f, 1.0f, 0.0f,
         1.0f, 1.0f, 1.0f,   //1.0f, 1.0f,   0.0f, 1.0f, 0.0f,

        // front
        -1.0f,-1.0f, 1.0f,   //1.0f, 0.0f,   0.0f, 0.0f, 1.0f,
         1.0f,-1.0f, 1.0f,   //0.0f, 0.0f,   0.0f, 0.0f, 1.0f,
        -1.0f, 1.0f, 1.0f,   //1.0f, 1.0f,   0.0f, 0.0f, 1.0f,
         1.0f,-1.0f, 1.0f,   //0.0f, 0.0f,   0.0f, 0.0f, 1.0f,
         1.0f, 1.0f, 1.0f,   //0.0f, 1.0f,   0.0f, 0.0f, 1.0f,
        -1.0f, 1.0f, 1.0f,   //1.0f, 1.0f,   0.0f, 0.0f, 1.0f,

        // back
        -1.0f,-1.0f,-1.0f,   //0.0f, 0.0f,   0.0f, 0.0f, -1.0f,
        -1.0f, 1.0f,-1.0f,   //0.0f, 1.0f,   0.0f, 0.0f, -1.0f,
         1.0f,-1.0f,-1.0f,   //1.0f, 0.0f,   0.0f, 0.0f, -1.0f,
         1.0f,-1.0f,-1.0f,   //1.0f, 0.0f,   0.0f, 0.0f, -1.0f,
        -1.0f, 1.0f,-1.0f,   //0.0f, 1.0f,   0.0f, 0.0f, -1.0f,
         1.0f, 1.0f,-1.0f,   //1.0f, 1.0f,   0.0f, 0.0f, -1.0f,

        // left
        -1.0f,-1.0f, 1.0f,   //0.0f, 1.0f,   -1.0f, 0.0f, 0.0f,
        -1.0f, 1.0f,-1.0f,   //1.0f, 0.0f,   -1.0f, 0.0f, 0.0f,
        -1.0f,-1.0f,-1.0f,   //0.0f, 0.0f,   -1.0f, 0.0f, 0.0f,
        -1.0f,-1.0f, 1.0f,   //0.0f, 1.0f,   -1.0f, 0.0f, 0.0f,
        -1.0f, 1.0f, 1.0f,   //1.0f, 1.0f,   -1.0f, 0.0f, 0.0f,
        -1.0f, 1.0f,-1.0f,   //1.0f, 0.0f,   -1.0f, 0.0f, 0.0f,

        // right
         1.0f,-1.0f, 1.0f,   //1.0f, 1.0f,   1.0f, 0.0f, 0.0f,
         1.0f,-1.0f,-1.0f,   //1.0f, 0.0f,   1.0f, 0.0f, 0.0f,
         1.0f, 1.0f,-1.0f,   //0.0f, 0.0f,   1.0f, 0.0f, 0.0f,
         1.0f,-1.0f, 1.0f,   //1.0f, 1.0f,   1.0f, 0.0f, 0.0f,
         1.0f, 1.0f,-1.0f,   //0.0f, 0.0f,   1.0f, 0.0f, 0.0f,
         1.0f, 1.0f, 1.0f,   //0.0f, 1.0f,   1.0f, 0.0f, 0.0f
	};

	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexBufferData), vertexBufferData, GL_STATIC_DRAW);

	// translate it so that it appears behind the FPS camera of Player
	transform = glm::translate(glm::mat4(), glm::vec3(0, 0, 4)) * glm::scale(glm::mat4(), glm::vec3(0.03, 0.03, 0.03)) * glm::rotate(glm::mat4(), 45.0f, glm::vec3(0, 0, 1));
}

void Projectile::drawProjectile()
{
	shader->use();

	shader->setUniform("camera", camera->matrix());
	shader->setUniform("model", transform);
	shader->setUniform("m_color", m_color);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	//glBindVertexArray(vertexArrayID);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glDrawArrays(GL_TRIANGLES, 0, 36);
}

void Projectile::updatePosition(float secondsElapsed, float upAngle, float rightAngle)
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

	camera->offsetCameraPosition(secondsElapsed * moveSpeed * -camera->forward());
	//transform = glm::translate(glm::mat4(), secondsElapsed * moveSpeed * -camera->forward()) * glm::scale(glm::mat4(), glm::vec3(0.03, 0.03, 0.03));
	camera->offsetOrientation(upAngle, rightAngle);
}