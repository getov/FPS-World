#pragma once

#include <vector>

namespace Util
{
	char* loadFile(const char* fileName, size_t* outFileSize = nullptr);

	glm::mat4 scale(GLfloat x, GLfloat y, GLfloat z);
	glm::mat4 translate(GLfloat x, GLfloat y, GLfloat z);
	glm::mat4 rotate(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
}