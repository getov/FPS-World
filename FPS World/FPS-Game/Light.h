#pragma once

class Light
{
	private:
		glm::vec3 position;
		glm::vec3 color;

	public:
		Light();
		~Light();

		void setPosition(glm::vec3 lightPos);
		void setColor(glm::vec3 lightColor);

		glm::vec3 getPosition();
		glm::vec3 getColor();
};