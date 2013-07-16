#pragma once

class GPUProgram;
class Camera;
class Texture;

class Camera;

class Skybox
{
	private:
		GPUProgram* shader;
		Texture* texture;
		GLuint vertexArrayID;
		GLuint vertexBuffer;
		glm::mat4 transform;

		//Camera* camera;

	public:
		Skybox();
		~Skybox();

		void prepareMaterial();
		void drawSkybox(Camera& gWorld);

		/*Camera* getSkyboxCamera();*/
};