#pragma once

class GPUProgram;
class Texture;

class WeaponModel
{
	private:
		GPUProgram* shader;
		Texture* texture;
		GLuint vertexArrayID;
		GLuint vertexBuffer;
		GLuint texBuffer;
		GLuint normalBuffer;
		glm::mat4 transform;

		//const char* filename;
		float* vertexArray;
		float* normalArray;
		float* uvArray;
		int numTriangles;
		int numUvCoords;

	public:
		WeaponModel();
		~WeaponModel();

		void prepareMaterial();
		void drawWeapon();
};