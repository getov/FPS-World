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

	public:
		WeaponModel();
		~WeaponModel();

		void prepareMaterial();
		void drawWeapon();
};