#include <GL\glew.h>
#include <GL\glfw.h>
#include <glm\glm.hpp>
#include <glm\gtc\type_ptr.hpp>

#include <iostream>

#include "Texture.h"
#include "GPUProgram.h"
#include "Util.h"

//size_t GPUProgram::boundTextures = 0;

GPUProgram::GPUProgram()
	: glFragmentShader(0)
	, glVertexShader(0)
	, boundTextures(0)
{
	glObject = glCreateProgram();
}

//
GPUProgram::GPUProgram(size_t numTexture)
	: glFragmentShader(0)
	, glVertexShader(0)
//	, boundTextures(numTexture)
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

//--------------------------------------

#define ATTRIB_N_UNIFORM_SETTERS(OGL_TYPE, TYPE_PREFIX, TYPE_SUFFIX) \
\
    void GPUProgram::setUniform(const GLchar* name, OGL_TYPE v0) \
        { glUniform1 ## TYPE_SUFFIX (uniform(name), v0); } \
    void GPUProgram::setUniform(const GLchar* name, OGL_TYPE v0, OGL_TYPE v1) \
        { glUniform2 ## TYPE_SUFFIX (uniform(name), v0, v1); } \
    void GPUProgram::setUniform(const GLchar* name, OGL_TYPE v0, OGL_TYPE v1, OGL_TYPE v2) \
        { glUniform3 ## TYPE_SUFFIX (uniform(name), v0, v1, v2); } \
    void GPUProgram::setUniform(const GLchar* name, OGL_TYPE v0, OGL_TYPE v1, OGL_TYPE v2, OGL_TYPE v3) \
        { glUniform4 ## TYPE_SUFFIX (uniform(name), v0, v1, v2, v3); } \
\
    void GPUProgram::setUniform1v(const GLchar* name, const OGL_TYPE* v, GLsizei count) \
        { glUniform1 ## TYPE_SUFFIX ## v (uniform(name), count, v); } \
    void GPUProgram::setUniform2v(const GLchar* name, const OGL_TYPE* v, GLsizei count) \
        { glUniform2 ## TYPE_SUFFIX ## v (uniform(name), count, v); } \
    void GPUProgram::setUniform3v(const GLchar* name, const OGL_TYPE* v, GLsizei count) \
        { glUniform3 ## TYPE_SUFFIX ## v (uniform(name), count, v); } \
    void GPUProgram::setUniform4v(const GLchar* name, const OGL_TYPE* v, GLsizei count) \
        { glUniform4 ## TYPE_SUFFIX ## v (uniform(name), count, v); }

	ATTRIB_N_UNIFORM_SETTERS(GLfloat, , f);
	ATTRIB_N_UNIFORM_SETTERS(GLdouble, , d);
	ATTRIB_N_UNIFORM_SETTERS(GLint, I, i);
	ATTRIB_N_UNIFORM_SETTERS(GLuint, I, ui);

//--------------------------------------

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

void GPUProgram::setUniform(const GLchar* name, const glm::vec3& v)
{
	setUniform3v(name, glm::value_ptr(v));
}

void GPUProgram::setUniform(const GLchar* name, const glm::vec4& v)
{
	setUniform4v(name, glm::value_ptr(v));
}

void GPUProgram::setUniform(const GLchar* name, const Texture& tex)
{
	assert(&tex);
	glActiveTexture(GL_TEXTURE0 + boundTextures);
	glBindTexture(tex.getTexType(), tex.getTexID());
	glUniform1i(uniform(name), boundTextures);

	++boundTextures;
}