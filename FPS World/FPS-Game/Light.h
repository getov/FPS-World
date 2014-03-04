#pragma once

class Light
{
	public:
		glm::vec3 color;
		glm::vec3 position;		

		// attenuation = 1 / (1 + attMult * distanceToLight^2)
		// multiplier that controls how fast the color of
		// the light increases or decreases
		// (for controlling the attenuation speed)
		float attMult;

		float ambientCoefficient;

		Light();

		Light(const glm::vec3& color, const glm::vec3& position,
			  const float& attenuationMult, const float& ambient);

		~Light();
};