#pragma once

class Light
{
	private:
		glm::vec3 position;
		glm::vec3 color;

		float attenuation;
		float ambientCoefficient;

	public:
		Light();
		~Light();

		void setPosition(glm::vec3 lightPos);
		void setColor(glm::vec3 lightColor);
		void setAttenuation(float att);
		void setAmbiendCoefficient(float ambient);

		glm::vec3 getPosition();
		glm::vec3 getColor();

		float getAttenuation();
		float getAmbientCoefficient();
};