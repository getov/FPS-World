#pragma once

#include <glm\glm.hpp>
#include <glm\gtc\type_ptr.hpp>

class Texture;

class GPUProgram
{
	private:
		GLuint glObject;
		GLuint glFragmentShader;
		GLuint glVertexShader;
		static size_t boundTextures;

		GLuint loadShader(GLenum shaderType, const char* shaderData);

	public:
		GPUProgram();
		GPUProgram(size_t numTexture);
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

#define PROGRAM_ATTRIB_N_UNIFORM_SETTERS(OGL_TYPE) \
\
        void setUniform(const GLchar* uniformName, OGL_TYPE v0); \
        void setUniform(const GLchar* uniformName, OGL_TYPE v0, OGL_TYPE v1); \
        void setUniform(const GLchar* uniformName, OGL_TYPE v0, OGL_TYPE v1, OGL_TYPE v2); \
        void setUniform(const GLchar* uniformName, OGL_TYPE v0, OGL_TYPE v1, OGL_TYPE v2, OGL_TYPE v3); \
\
        void setUniform1v(const GLchar* uniformName, const OGL_TYPE* v, GLsizei count=1); \
        void setUniform2v(const GLchar* uniformName, const OGL_TYPE* v, GLsizei count=1); \
        void setUniform3v(const GLchar* uniformName, const OGL_TYPE* v, GLsizei count=1); \
        void setUniform4v(const GLchar* uniformName, const OGL_TYPE* v, GLsizei count=1); \

        PROGRAM_ATTRIB_N_UNIFORM_SETTERS(GLfloat)
        PROGRAM_ATTRIB_N_UNIFORM_SETTERS(GLdouble)
        PROGRAM_ATTRIB_N_UNIFORM_SETTERS(GLint)
        PROGRAM_ATTRIB_N_UNIFORM_SETTERS(GLuint)

		void setUniform(const GLchar* name, const glm::mat2 &matrix, GLboolean transpose = GL_FALSE);
		void setUniform(const GLchar* name, const glm::mat3 &matrix, GLboolean transpose = GL_FALSE);
		void setUniform(const GLchar* name, const glm::mat4 &matrix, GLboolean transpose = GL_FALSE);
		void setUniform(const GLchar* uniformName, const glm::vec3& v);
        void setUniform(const GLchar* uniformName, const glm::vec4& v);
		void setUniform(const GLchar* name, const Texture& tex);
};