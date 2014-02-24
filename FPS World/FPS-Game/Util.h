#pragma once

#include <vector>
#include <string>

namespace Util
{
	char* loadFile(const char* fileName, size_t* outFileSize = nullptr);

	int parseToInt(const std::string& s);
	double parseToDouble(const std::string& s);
	std::vector<std::string> tokenize(std::string s);

	// wrapper functions for more intuitive interface
	glm::mat4 scale(GLfloat x, GLfloat y, GLfloat z);
	glm::mat4 translate(GLfloat x, GLfloat y, GLfloat z);
	glm::mat4 rotate(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
}