#pragma once

#include <glm\glm.hpp>
#include <glm\gtc\type_ptr.hpp>

class GPUProgram
{
	private:
		GLuint glObject;
		GLuint glFragmentShader;
		GLuint glVertexShader;

		GLuint loadShader(GLenum shaderType, const char* shaderData);

	public:
		GPUProgram();
		~GPUProgram();

		bool loadFragmentShaderFromFile(const char* fileName);
		bool loadFragmentShader(const char* shaderData);

		bool loadVertexShaderFromFile(const char* fileName);
		bool loadVertexShader(const char* shaderData);

		bool link();
		void use();
		void stopUsing();

		GLint uniform(const char* name) const;
		GLint bindAttribute(const char* name);

		void setUniform(const GLchar* name, const glm::mat2 &matrix, GLboolean transpose = GL_FALSE);
		void setUniform(const GLchar* name, const glm::mat3 &matrix, GLboolean transpose = GL_FALSE);
		void setUniform(const GLchar* name, const glm::mat4 &matrix, GLboolean transpose = GL_FALSE);
};