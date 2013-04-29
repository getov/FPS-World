#include <GL\glew.h>
#include <GL\glfw.h>
#include <glm\glm.hpp>
#include <glm\gtc\type_ptr.hpp>

#include <iostream>

#include "GPUProgram.h"
#include "Util.h"

GPUProgram::GPUProgram()
	: glFragmentShader(0)
	, glVertexShader(0)
{
	glObject = glCreateProgram();
}

GPUProgram::~GPUProgram()
{
	if (glObject)
	{
		glDeleteProgram(glObject);
	}

	if (glFragmentShader)
	{
		glDeleteProgram(glFragmentShader);
	}

	if (glVertexShader)
	{
		glDeleteProgram(glVertexShader);
	}
}

bool GPUProgram::loadFragmentShaderFromFile(const char* fileName)
{
	const char* fileContents = Util::loadFile(fileName);

	bool result = loadFragmentShader(fileContents);

	delete[] fileContents;

	return result;
}

bool GPUProgram::loadFragmentShader(const char* shaderData)
{
	glFragmentShader = loadShader(GL_FRAGMENT_SHADER, shaderData);
	return !!glFragmentShader;
}

bool GPUProgram::loadVertexShaderFromFile(const char* fileName)
{
	const char* fileContents = Util::loadFile(fileName);

	bool result = loadVertexShader(fileContents);

	delete[] fileContents;

	return result;
}

bool GPUProgram::loadVertexShader(const char* shaderData)
{
	glVertexShader = loadShader(GL_VERTEX_SHADER, shaderData);
	return !!glVertexShader;
}

GLuint GPUProgram::loadShader(GLenum shaderType, const char* shaderData)
{
	GLuint shader = glCreateShader(shaderType);

	if (!shader)
	{
		return 0;
	}

	glShaderSource(shader, 1, &shaderData, nullptr);
	glCompileShader(shader);

	GLint compiled;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);

	// optional
	GLint infoLen = 0;
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);

	if (infoLen > 1)
	{
		char* infoLog = new char[infoLen];

		glGetShaderInfoLog(shader, infoLen, nullptr, infoLog);

		if (!compiled)
		{
			std::cerr << "Error compiling shader:";
		}
		else
		{
			std::cerr << "Shader compilation result:";
		}

		std::cerr << std::endl << infoLog << std::endl;

		delete[] infoLog;
	}
	// optional - end

	if (!compiled)
	{
		glDeleteShader(shader);
		return 0;
	}

	glAttachShader(glObject, shader);

	return shader;
}

bool GPUProgram::link()
{
	glLinkProgram(glObject);

	GLint linked;
	glGetProgramiv(glObject, GL_LINK_STATUS, &linked);

	if (!linked)
	{
		GLint infoLen = 0;

		glGetProgramiv(glObject, GL_INFO_LOG_LENGTH, &infoLen);

		if (infoLen > 1)
		{
			char* infoLog = new char[infoLen];

			glGetProgramInfoLog(glObject, infoLen, nullptr, infoLog);
			std::cerr << "Error linking program:\n" << infoLog << std::endl;

			delete[] infoLog;
		}

		glDeleteProgram(glObject);
		return false;
	}

	return true;
}

void GPUProgram::use()
{
	glUseProgram(glObject);
}

void GPUProgram::stopUsing()
{
	glUseProgram(0);
}

GLint GPUProgram::bindAttribute(const char* name)
{
	return glGetAttribLocation(glObject, name);
}

GLint GPUProgram::uniform(const char* name) const
{
	return glGetUniformLocation(glObject, name);
}

void GPUProgram::setUniform(const char* name, const glm::mat2 &matrix, GLboolean transpose)
{
	glUniformMatrix2fv(uniform(name), 1, transpose, glm::value_ptr(matrix));
}

void GPUProgram::setUniform(const char* name, const glm::mat3 &matrix, GLboolean transpose)
{
	glUniformMatrix3fv(uniform(name), 1, transpose, glm::value_ptr(matrix));
}

void GPUProgram::setUniform(const char* name, const glm::mat4 &matrix, GLboolean transpose)
{
	glUniformMatrix4fv(uniform(name), 1, transpose, glm::value_ptr(matrix));
}