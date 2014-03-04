#pragma once

class GPUProgram;
class Texture;
class Camera;

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

		std::vector<glm::vec3> vertices;
		std::vector<glm::vec3> normals;
		std::vector<glm::vec2> uvs;
		std::vector<GLushort> elements;

		bool loadFromOBJ(const char* fileName);

		bool loadOBJ(
			const char * path, 
			std::vector<glm::vec3> & out_vertices, 
			std::vector<glm::vec2> & out_uvs, 
			std::vector<glm::vec3> & out_normals
		);

	public:
		WeaponModel();
		~WeaponModel();

		void prepareMaterial();
		void drawWeapon(Camera& world);
};