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
		glm::mat4 transform;
		std::vector<glm::vec3> vertices;
		std::vector<glm::vec2> uvs;
		std::vector<glm::vec3> normals;

	public:
		WeaponModel();
		~WeaponModel();

		void prepareMaterial();
		void drawWeapon();
};