#include "Projectile.h"

#include <GL\glew.h>
#include <GL\glfw.h>

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

#include "GPUProgram.h"
#include "Camera.h"
#include "Light.h"
#include "Texture.h"

Projectile::Projectile()
	: shader(nullptr)
	, texture(nullptr)
	, vertexArrayID(0)
	, moveSpeed(0.1f)
	, degreesPerSecond(180.0f)
	, degreesRotated(0.0f)
	, fragShaderName("PhongReflectionTex.frag")
	, textureName("wooden-crate.jpg")
	, useTexture(true)
{
}

Projectile::Projectile(const glm::vec4& color, const char* fragShader, const char* texName, bool useTex)
	: shader(nullptr)
	, texture(nullptr)
	, vertexArrayID(0)
	, moveSpeed(0.1f)
	, degreesPerSecond(180.0f)
	, degreesRotated(0.0f)
	, m_color(color)
	, fragShaderName(fragShader)
	, textureName(texName)
	, useTexture(useTex)
{
}

Projectile::~Projectile()
{
	glDeleteBuffers(1, &vertexBuffer);
	glDeleteVertexArrays(1, &vertexArrayID);
	delete shader;
	delete texture;
}

void Projectile::prepareMaterial()
{
	glGenVertexArrays(1, &vertexArrayID);
	glBindVertexArray(vertexArrayID);

	shader = new GPUProgram;

	shader->loadFragmentShaderFromFile(fragShaderName);
	shader->loadVertexShaderFromFile("box.vert");

	shader->link();

	static const GLfloat vertexBufferData[] = {
	
		 //  X     Y     Z       U     V          Normal
        // bottom
        -1.0f,-1.0f,-1.0f,   0.0f, 0.0f,   0.0f, -1.0f, 0.0f,
         1.0f,-1.0f,-1.0f,   1.0f, 0.0f,   0.0f, -1.0f, 0.0f,
        -1.0f,-1.0f, 1.0f,   0.0f, 1.0f,   0.0f, -1.0f, 0.0f,
         1.0f,-1.0f,-1.0f,   1.0f, 0.0f,   0.0f, -1.0f, 0.0f,
         1.0f,-1.0f, 1.0f,   1.0f, 1.0f,   0.0f, -1.0f, 0.0f,
        -1.0f,-1.0f, 1.0f,   0.0f, 1.0f,   0.0f, -1.0f, 0.0f,

        // top
        -1.0f, 1.0f,-1.0f,   0.0f, 0.0f,   0.0f, 1.0f, 0.0f,
        -1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   0.0f, 1.0f, 0.0f,
         1.0f, 1.0f,-1.0f,   1.0f, 0.0f,   0.0f, 1.0f, 0.0f,
         1.0f, 1.0f,-1.0f,   1.0f, 0.0f,   0.0f, 1.0f, 0.0f,
        -1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   0.0f, 1.0f, 0.0f,
         1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   0.0f, 1.0f, 0.0f,

        // front
        -1.0f,-1.0f, 1.0f,   1.0f, 0.0f,   0.0f, 0.0f, 1.0f,
         1.0f,-1.0f, 1.0f,   0.0f, 0.0f,   0.0f, 0.0f, 1.0f,
        -1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   0.0f, 0.0f, 1.0f,
         1.0f,-1.0f, 1.0f,   0.0f, 0.0f,   0.0f, 0.0f, 1.0f,
         1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   0.0f, 0.0f, 1.0f,
        -1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   0.0f, 0.0f, 1.0f,

        // back
        -1.0f,-1.0f,-1.0f,   0.0f, 0.0f,   0.0f, 0.0f, -1.0f,
        -1.0f, 1.0f,-1.0f,   0.0f, 1.0f,   0.0f, 0.0f, -1.0f,
         1.0f,-1.0f,-1.0f,   1.0f, 0.0f,   0.0f, 0.0f, -1.0f,
         1.0f,-1.0f,-1.0f,   1.0f, 0.0f,   0.0f, 0.0f, -1.0f,
        -1.0f, 1.0f,-1.0f,   0.0f, 1.0f,   0.0f, 0.0f, -1.0f,
         1.0f, 1.0f,-1.0f,   1.0f, 1.0f,   0.0f, 0.0f, -1.0f,

        // left
        -1.0f,-1.0f, 1.0f,   0.0f, 1.0f,   -1.0f, 0.0f, 0.0f,
        -1.0f, 1.0f,-1.0f,   1.0f, 0.0f,   -1.0f, 0.0f, 0.0f,
        -1.0f,-1.0f,-1.0f,   0.0f, 0.0f,   -1.0f, 0.0f, 0.0f,
        -1.0f,-1.0f, 1.0f,   0.0f, 1.0f,   -1.0f, 0.0f, 0.0f,
        -1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   -1.0f, 0.0f, 0.0f,
        -1.0f, 1.0f,-1.0f,   1.0f, 0.0f,   -1.0f, 0.0f, 0.0f,

        // right
         1.0f,-1.0f, 1.0f,   1.0f, 1.0f,   1.0f, 0.0f, 0.0f,
         1.0f,-1.0f,-1.0f,   1.0f, 0.0f,   1.0f, 0.0f, 0.0f,
         1.0f, 1.0f,-1.0f,   0.0f, 0.0f,   1.0f, 0.0f, 0.0f,
         1.0f,-1.0f, 1.0f,   1.0f, 1.0f,   1.0f, 0.0f, 0.0f,
         1.0f, 1.0f,-1.0f,   0.0f, 0.0f,   1.0f, 0.0f, 0.0f,
         1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   1.0f, 0.0f, 0.0f
	};

	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexBufferData), vertexBufferData, GL_STATIC_DRAW);

	if (useTexture)
	{
		texture = new Texture;
		texture->loadTexture(textureName);
		//shader->setUniform("tex", *texture);
	}
	/*else
	{
		shader->setUniform("m_color", m_color);
	}*/
	
	setShininess(80.0f);
	setSpecularColor(glm::vec3(1.0f, 1.0f, 1.0f));

	// vertices
	glEnableVertexAttribArray(0);	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8*sizeof(GLfloat), NULL);

	// connect the normal to the "vertNormal" attribute of the vertex shader
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_TRUE, 8*sizeof(GLfloat), (const GLvoid*)(5 * sizeof(GLfloat)));

	// connect the uv coords to the "vertTexCoord" attribute of the vertex shader
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_TRUE,  8*sizeof(GLfloat), (const GLvoid*)(3 * sizeof(GLfloat)));

	// unbind VBO and VAO
	glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

glm::vec4 Projectile::getDiffuseColor()
{
	return m_color;
}

void Projectile::setShininess(GLfloat shine)
{
	shininess = shine;
}

void Projectile::setSpecularColor(glm::vec3 color)
{
	specularColor = color;
}

GLfloat Projectile::getShininess()
{
	return shininess;
}

glm::vec3 Projectile::getSpecularColor()
{
	return specularColor;
}

GPUProgram* Projectile::getShader()
{
	return shader;
}

Texture* Projectile::getTexture()
{
	return texture;
}

GLuint Projectile::getVAO()
{
	return vertexArrayID;
}

// setters and getters for movement controls
float Projectile::getMoveSpeed()
{
	return moveSpeed;
}

GLfloat Projectile::getDegreesPerSecond()
{
	return degreesPerSecond;
}

float Projectile::getDegreesRotated()
{
	return degreesRotated;
}

void Projectile::setMoveSpeed(const float& speed)
{
	moveSpeed = speed;
}

void Projectile::setDegreesPerSecond(const float& degPerSecond)
{
	degreesPerSecond = degPerSecond;
}

void Projectile::setDegreesRotated(const float& degRotated)
{
	degreesRotated += degRotated;
}