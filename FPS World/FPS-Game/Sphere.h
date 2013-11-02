#pragma once

class GPUProgram;
class Camera;
class Light;

class Sphere
{
	private:
		float PI;

		std::vector<GLfloat> vertices;
		std::vector<GLfloat> normals;
		std::vector<GLfloat> texcoords;
		std::vector<GLushort> indices;

		float m_radius;
		unsigned int sectors;
		unsigned int rings;

		GPUProgram* shader;
		GLuint vertexArrayID;
		GLuint vertexBuffer;
		glm::mat4 transform;

		GLfloat shininess;
		glm::vec3 specularColor;
		glm::vec4 m_color;

		float moveSpeed;
		GLfloat degreesPerSecond;
		float degreesRotated;

	public:
		Sphere();
		Sphere(const float& radius, glm::vec4 color);
		~Sphere();

		void prepareMaterial(Camera& camera);
		void setShininess(GLfloat shine);
		void setSpecularColor(glm::vec3 color);

		GPUProgram* getShader();
		GLuint getVAO();

		GLfloat getShininess();
		glm::vec3 getSpecularColor();

		// functions for movement control over the sphere
		float getMoveSpeed();
		GLfloat getDegreesPerSecond();
		float getDegreesRotated();

		void setMoveSpeed(float speed);
		void setDegreesPerSecond(float degPerSecond);
		void setDegreesRotated(float degRotated);

		void renderSphere(Camera& gWorld, Light& gLight);
};