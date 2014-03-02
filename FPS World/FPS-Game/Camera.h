#pragma once

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

class Camera
{
	private:
		glm::vec3 position;
		float horizontalAngle;
		float verticalAngle;
		float fieldOfView;
		float nearPlane;
		float farPlane;
		float viewportRatio;

		glm::vec3 m_velocity;
		glm::vec3 m_gravity;

		mutable float q;
		mutable float n;

	public:
		Camera();

		bool useQuat;

		// position of the camera
		const glm::vec3 &cameraPosition() const;
		void setCameraPosition(const glm::vec3 &cameraPosition);
		void offsetCameraPosition(const glm::vec3 &offset);

		// the vertical viewing angle of the camera in degrees
		float cameraFieldOfView() const;
		void setCameraFieldOfView(float cameraFieldOfView);

		float nearClipPlane() const;
		float farClipPlane() const;

		void setNearAndFarPlanes(float nearClipPlane, float farClipPlane);

		// A rotation matrix that determines the direction the camera is looking.
		glm::mat4 orientation() const;

		// A rotation matrix that rotates the camera only about the 'Y' axis
		glm::mat4 horizontalOrientation() const;

		// Offsets the camera's orientation.
		void offsetOrientation(float upAngle, float rightAngle);

		// The width divided by the height of the screen/window/viewport
		float viewportAspectRatio() const;
		void setViewportAspectRatio(float viewportAspectRatio);

		/** A unit vector representing the direction the camera is facing */
		glm::vec3 forward() const;

		/** A unit vector representing the direction to the right of the camera*/
        glm::vec3 right() const;

        /** A unit vector representing the direction out of the top of the camera*/
        glm::vec3 up() const;

		/**
		 * @brief - Vector representing direction for jumping
		 * @return - Camera::m_velocity
		*/
		glm::vec3 velocity();

		/**
		 * @brief - A gravity vector
		 * @return - Camera::m_gravity
		*/
		glm::vec3 gravity();

		/**
		 * @brief - 
		*/
		void updateVelocity(glm::vec3 offset);
		void resetVelocity();

		/**
         The combined camera transformation matrix, including perspective projection.

         This is the complete matrix to use in the vertex shader.
         */
        glm::mat4 matrix() const;

		/**
         The perspective projection transformation matrix
         */
        glm::mat4 projection() const;

        /**
         The translation and rotation matrix of the camera.

         Same as the `matrix` method, except the return value does not include the projection
         transformation.
         */
        glm::mat4 view() const;

		glm::mat4 quaternion() const;
};