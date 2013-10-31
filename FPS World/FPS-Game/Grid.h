#pragma once

class GPUProgram;
class Camera;

class Grid
{
	private:
		GPUProgram* shader;
		GLuint vertexArrayID;
		GLuint vertexBuffer;
		GLuint indexBuffer;
		glm::mat4 transform;

		struct Point {
		  GLfloat x;
		  GLfloat y;
		};

		static const int GRID_LINES;

	public:
		Grid();
		~Grid();

		void prepareMaterial();
		void drawGrid(Camera& gWorld);
};