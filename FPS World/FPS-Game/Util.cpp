#include <fstream>
#include <vector>
#include <stdio.h>
#include <string>
#include <cstring>

#include <GL\glew.h>
#include <GL\glfw.h>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

#include "Util.h"

namespace Util
{
	char* loadFile(const char* fileName, size_t* outFileSize)
	{
		std::ifstream file(fileName, std::ios::in | std::ios::binary);

		if (!file.is_open())
		{
			return nullptr;
		}

		std::streamoff begin = file.tellg();
		file.seekg(0, std::ios::end);
		size_t fileSize = size_t(file.tellg() - begin);
		file.seekg(0, std::ios::beg);

		char* fileContents = new char[fileSize + 1];

		file.read(fileContents, fileSize);

		fileContents[fileSize] = 0;

		if (outFileSize)
		{
			*outFileSize = fileSize;
		}

		return fileContents;
	}

	glm::mat4 scale(GLfloat x, GLfloat y, GLfloat z)
	{
		return glm::scale(glm::mat4(), glm::vec3(x, y, z));
	}

	glm::mat4 translate(GLfloat x, GLfloat y, GLfloat z)
	{
		return glm::translate(glm::mat4(), glm::vec3(x, y, z));
	}

	glm::mat4 rotate(GLfloat angle, GLfloat x, GLfloat y, GLfloat z)
	{
		return glm::rotate(glm::mat4(), angle, glm::vec3(x, y, z));
	}
}