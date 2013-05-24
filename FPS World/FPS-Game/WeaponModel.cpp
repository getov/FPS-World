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
	//delete texture;
}

void WeaponModel::prepareMaterial()
{
	glGenVertexArrays(1, &vertexArrayID);
	glBindVertexArray(vertexArrayID);

	/*texture = new Texture;
	texture->loadTexture("bg.bmp");*/

	shader = new GPUProgram;

	//shader->loadFragmentShaderFromFile("weaponModel.frag");
	shader->loadVertexShaderFromFile("weaponModel.vert");

	shader->link();

	bool res = Util::loadOBJ("ak.obj", vertices, uvs, normals);

	glGenBuffers(1, &vertexArrayID);
	glBindBuffer(GL_ARRAY_BUFFER, vertexArrayID);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);

	transform = Util::scale(0.5, 0.5, 0.5);
}

void WeaponModel::drawWeapon()
{
	shader->use();

	shader->setUniform("model", transform);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glDrawArrays(GL_TRIANGLES, 0, vertices.size());
}