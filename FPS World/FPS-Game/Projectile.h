#pragma once

class GPUProgram;
class Camera;

class Projectile
{
	private:
		GPUProgram* shader;
		Camera* camera;
		GLuint vertexArrayID;
		GLuint vertexBuffer;
		glm::mat4 transform;
		float moveSpeed;

		glm::vec3 m_color;

	public:
		Projectile();
		~Projectile();

		void prepareMaterial();
		void drawProjectile();
		void updatePosition(float secondsElapsed, float upAngle, float rightAngle);
};