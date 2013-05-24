#include <GL\glew.h>
#include <GL\glfw.h>

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

#include <vector>

#include "GPUProgram.h"
#include "Texture.h"
#include "WeaponModel.h"
#include "Util.h"

WeaponModel::WeaponModel()
	: shader(nullptr)
	, texture(nullptr)
	, vertexArrayID(0)
	, transform()
{
}

WeaponModel::~WeaponModel()
{
	glDeleteBuffers(1, &vertexBuffer);
	glDeleteVertexArrays(1, &vertexArrayID);
	delete shader;
	delete texture;
}

void WeaponModel::prepareMaterial()
{
	glGenVertexArrays(1, &vertexArrayID);
	glBindVertexArray(vertexArrayID);

	texture = new Texture;
	texture->loadTexture("cs.bmp");

	shader = new GPUProgram(1);

	shader->loadFragmentShaderFromFile("weaponModel.frag");
	shader->loadVertexShaderFromFile("weaponModel.vert");

	shader->link();

	GLfloat vertexBufferData[] = {
	//     X     Y    Z       U    V
		0.01, 0.10, 0.0,	1.0, 1.0, /*0.0, 0.0,*/ 
		0.01, 0.20, 0.0,	1.0, 0.0, /*0.0, 1.0,*/ 
		0.30, 0.20, 0.0,	0.0, 0.0, /*1.0, 1.0,*/ 

		0.01, 0.10, 0.0,	1.0, 1.0, /*0.0, 0.0,*/ 
		0.30, 0.20, 0.0,	0.0, 0.0, /*1.0, 1.0,*/ 
		0.30, 0.10, 0.0,	0.0, 1.0  /*1.0, 0.0*/ 
	};

	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexBufferData), vertexBufferData, GL_STATIC_DRAW);

	shader->setUniform("tex", *texture);
	
	transform = Util::translate(-1.1, -2.0, 0.0) * Util::scale(4.0, 10.0, 0.0);
}

void WeaponModel::drawWeapon()
{
	shader->use();

	shader->setUniform("model", transform);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexArrayID);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5*sizeof(GLfloat), NULL);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_TRUE,  5*sizeof(GLfloat), (const GLvoid*)(3 * sizeof(GLfloat)));

	glDrawArrays(GL_TRIANGLES, 0, 6);
}