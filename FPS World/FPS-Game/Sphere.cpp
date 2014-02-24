#include <GL\glew.h>
#include <GL\glfw.h>

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

#include <vector>
#include "Sphere.h"
#include "Box.h"
#include "GPUProgram.h"
#include "Camera.h"
#include "Light.h"

Sphere::Sphere()
	: shader(nullptr)
	, vertexArrayID(0)
	, moveSpeed(0.1f)
	, degreesPerSecond(180.0f)
	, degreesRotated(0.0f)
	, rings(100)
	, sectors(20)
	, m_radius(2.0)
	, m_color(0.5, 0.4, 0.0, 0.0)
	, PI(3.14159265358979f)
{
}

Sphere::Sphere(const float& radius, glm::vec4 color)
	: shader(nullptr)
	, vertexArrayID(0)
	, moveSpeed(0.1f)
	, degreesPerSecond(180.0f)
	, degreesRotated(0.0f)
	, rings(100)
	, sectors(20)
	, m_radius(radius)
	, m_color(color)
	, PI(3.14159265358979f)
{
}

Sphere::~Sphere()
{
	delete shader;
}

void Sphere::prepareMaterial(Camera& camera)
{
	glGenVertexArrays(1, &vertexArrayID);
	glBindVertexArray(vertexArrayID);
	

	shader = new GPUProgram;

	shader->loadFragmentShaderFromFile("PhongReflection.frag");
	shader->loadVertexShaderFromFile("Sphere.vert");

	shader->link();

	float const R = 1./(float)(rings-1);
    float const S = 1./(float)(sectors-1);
    int r, s;
	
    vertices.resize(rings * sectors * 3);
    normals.resize(rings * sectors * 3);
    texcoords.resize(rings * sectors * 2);
    std::vector<GLfloat>::iterator v = vertices.begin();
    std::vector<GLfloat>::iterator n = normals.begin();
    std::vector<GLfloat>::iterator t = texcoords.begin();
    for(r = 0; r < rings; r++) 
	{
		for(s = 0; s < sectors; s++)
		{
				float const y = sin( -PI*PI + PI * r * R );
				float const x = cos(2*PI * s * S) * sin( PI * r * R );
				float const z = sin(2*PI * s * S) * sin( PI * r * R );

				*t++ = s*S;
				*t++ = r*R;
				
				*v++ = x * m_radius;
				*v++ = y * m_radius;
				*v++ = z * m_radius;

				*n++ = x;
				*n++ = y;
				*n++ = z;
		}
	}

    indices.resize(rings * sectors * 4);
    std::vector<GLushort>::iterator i = indices.begin();
    for(r = 0; r < rings-1; r++) for(s = 0; s < sectors-1; s++)
	{
            *i++ = r * sectors + s;
            *i++ = r * sectors + (s+1);
            *i++ = (r+1) * sectors + (s+1);
            *i++ = (r+1) * sectors + s;
    }

	GLsizeiptr vertexBufferSize = vertices.size() + 
								  normals.size() + 
								  texcoords.size() + 
								  indices.size();

	std::vector<GLfloat> vertexBufferData;
	for (auto i = vertices.begin(); i != vertices.end(); ++i)
	{
		vertexBufferData.push_back(*i);
	}
	for (auto i = normals.begin(); i != normals.end(); ++i)
	{
		vertexBufferData.push_back(*i);
	}
	for (auto i = texcoords.begin(); i != texcoords.end(); ++i)
	{
		vertexBufferData.push_back(*i);
	}

	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertexBufferSize, &vertexBufferData, GL_STATIC_DRAW);
	
	transform = glm::translate(glm::mat4(), glm::vec3(2.5f, 1.0f, -2.0f)) * glm::scale(glm::mat4(), glm::vec3(2.0, 2.0, 2.0));

	setShininess(80.0f);
	setSpecularColor(glm::vec3(1.0f, 1.0f, 1.0f));
}

void Sphere::setShininess(GLfloat shine)
{
	shininess = shine;
}

void Sphere::setSpecularColor(glm::vec3 color)
{
	specularColor = color;
}

GLfloat Sphere::getShininess()
{
	return shininess;
}

glm::vec3 Sphere::getSpecularColor()
{
	return specularColor;
}

GPUProgram* Sphere::getShader()
{
	return shader;
}

GLuint Sphere::getVAO()
{
	return vertexArrayID;
}

// setters and getters for movement controls
float Sphere::getMoveSpeed()
{
	return moveSpeed;
}

GLfloat Sphere::getDegreesPerSecond()
{
	return degreesPerSecond;
}

float Sphere::getDegreesRotated()
{
	return degreesRotated;
}

void Sphere::setMoveSpeed(float speed)
{
	moveSpeed = speed;
}

void Sphere::setDegreesPerSecond(float degPerSecond)
{
	degreesPerSecond = degPerSecond;
}

void Sphere::setDegreesRotated(float degRotated)
{
	degreesRotated += degRotated;
}

void Sphere::renderSphere(Camera& gWorld, Light& gLight)
{
	shader->use();

	shader->setUniform("camera", gWorld.matrix());
	shader->setUniform("model", transform);
	shader->setUniform("m_color", m_color);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8*sizeof(GLfloat), &vertices[0]);
	

	// connect the normal to the "vertNormal" attribute of the vertex shader
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_TRUE, 8*sizeof(GLfloat), &normals[0]);

	shader->setUniform("material.shininess", shininess);
	shader->setUniform("material.specularColor", specularColor);
	shader->setUniform("light.position", gLight.getPosition());
	shader->setUniform("light.intensities", gLight.getColor());
	shader->setUniform("light.attenuation", gLight.getAttenuation());
	shader->setUniform("light.ambientCoefficient", gLight.getAmbientCoefficient());
	shader->setUniform("cameraPosition", gWorld.cameraPosition());

	glDrawElements(GL_QUADS, indices.size(), GL_UNSIGNED_SHORT, &indices[0]);
}