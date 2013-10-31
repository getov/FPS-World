#include <GL\glew.h>
#include <GL\glfw.h>

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <vector>

#include "Grid.h"
#include "GPUProgram.h"
#include "Camera.h"
#include "Util.h"

const int Grid::GRID_LINES = 52;

Grid::Grid()
	: shader(nullptr)
	, vertexArrayID(0)
{
}

Grid::~Grid()
{
	glDeleteBuffers(1, &vertexBuffer);
	glDeleteBuffers(1, &indexBuffer);
	glDeleteVertexArrays(1, &vertexArrayID);
	delete shader;
}

void Grid::prepareMaterial()
{
	glGenVertexArrays(1, &vertexArrayID);
	glBindVertexArray(vertexArrayID);

	shader = new GPUProgram;

	shader->loadFragmentShaderFromFile("grid.frag");
	shader->loadVertexShaderFromFile("grid.vert");

	shader->link();
 
	Point vertices[GRID_LINES][GRID_LINES];
 
	for(int i = 0; i < GRID_LINES; i++) 
	{
	  for(int j = 0; j < GRID_LINES; j++)
	  {
		vertices[i][j].x = (j - ((GRID_LINES - 1)/2)) / static_cast<GLfloat>(((GRID_LINES - 1)/2));
		vertices[i][j].y = (i - ((GRID_LINES - 1)/2)) / static_cast<GLfloat>(((GRID_LINES - 1)/2));
	  }
	}
 
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	GLuint indices[2 * (GRID_LINES - 1) * GRID_LINES * 2];
	int i = 0;
 
	// Horizontal grid lines
	for(int y = 0; y < GRID_LINES; y++) 
	{
	  for(int x = 0; x < GRID_LINES - 1; x++)
	  {
		indices[i++] = static_cast<GLuint>(y * GRID_LINES + x);
		indices[i++] = static_cast<GLuint>(y * GRID_LINES + x + 1);
	  }
	}
 
	// Vertical grid lines
	for(int x = 0; x < GRID_LINES; x++)
	{
	  for(int y = 0; y < GRID_LINES - 1; y++) 
	  {
		indices[i++] = static_cast<GLuint>(y * GRID_LINES + x);
		indices[i++] = static_cast<GLuint>((y + 1) * GRID_LINES + x);
	  }
	}
 
	glGenBuffers(1, &indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	transform = Util::rotate(90.0f, 1.0f, 0.0f, 0.0f) * Util::translate(0.0f, 0.0f, 0.31f) * Util::scale(7.0f, 7.0f, 7.0f);
}

void Grid::drawGrid(Camera& gWordl)
{
	shader->use();

	shader->setUniform("camera", gWordl.matrix());
	shader->setUniform("model", transform);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glDrawElements(GL_LINES, 2 * (GRID_LINES - 1) * GRID_LINES * 2, GL_UNSIGNED_INT, 0);
}