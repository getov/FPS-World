#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

#include "Camera.h"

static const float MAX_VERTICAL_ANGLE = 85.0f;

Camera::Camera()
	: position(0.0f, 0.0f, 1.0f)
	, horizontalAngle(0.0f)
	, verticalAngle(0.0f)
	, fieldOfView(50.0f)
	, nearPlane(0.01f)
	, farPlane(100.0f)
	, viewportRatio(4.0f / 3.0f)
{
}

const glm::vec3 &Camera::cameraPosition() const
{
	return position;
}

void Camera::setCameraPosition(const glm::vec3 &cameraPosition)
{
	position = cameraPosition;
}

void Camera::offsetCameraPosition(const glm::vec3 &offset)
{
	position += offset;
}

float Camera::cameraFieldOfView() const
{
	return fieldOfView;
}

void Camera::setCameraFieldOfView(float cameraFieldOfView)
{
	assert(cameraFieldOfView > 0.0f && cameraFieldOfView < 180.0f);
	fieldOfView = cameraFieldOfView;
}

float Camera::nearClipPlane() const
{
	return nearPlane;
}

float Camera::farClipPlane() const
{
	return farPlane;
}

void Camera::setNearAndFarPlanes(float nearClipPlane, float farClipPlane)
{
	assert(nearClipPlane > 0.0f);
	assert(farClipPlane > nearClipPlane);

	nearPlane = nearClipPlane;
	farPlane  = farClipPlane;
}

glm::mat4 Camera::orientation() const
{
	glm::mat4 orientation;

	orientation = glm::rotate(orientation, verticalAngle, glm::vec3(1, 0, 0));
	orientation = glm::rotate(orientation, horizontalAngle, glm::vec3(0, 1, 0));

	return orientation;
}

void Camera::offsetOrientation(float upAngle, float rightAngle)
{
	horizontalAngle += rightAngle;
	while (horizontalAngle > 360.0f)
	{
		horizontalAngle -= 360.0;
	}
	while (horizontalAngle < 0.0f)
	{
		horizontalAngle += 360.0;
	}

	// to prevent gimbal lock
	verticalAngle += upAngle;
	if (verticalAngle > MAX_VERTICAL_ANGLE)
	{
		verticalAngle = MAX_VERTICAL_ANGLE;
	}
	if (verticalAngle < -MAX_VERTICAL_ANGLE)
	{
		verticalAngle = -MAX_VERTICAL_ANGLE;
	}
}

float Camera::viewportAspectRatio() const
{
	return viewportRatio;
}

void Camera::setViewportAspectRatio(float viewportAspectRatio)
{
	assert(viewportAspectRatio > 0.0);
	viewportRatio = viewportAspectRatio;
}

glm::vec3 Camera::forward() const
{
	glm::vec4 forward = glm::inverse(orientation()) * glm::vec4(0, 0, -1, 1);

	return glm::vec3(forward);
}

glm::vec3 Camera::right() const
{
	glm::vec4 right = glm::inverse(orientation()) * glm::vec4(1, 0, 0, 1);

	return glm::vec3(right);
}

glm::vec3 Camera::up() const
{
	glm::vec4 up = glm::inverse(orientation()) * glm::vec4(0, 1, 0, 1);

	return glm::vec3(up);
}

glm::mat4 Camera::matrix() const
{
	return projection() * view();
}

glm::mat4 Camera::projection() const
{
	return glm::perspective(fieldOfView, viewportRatio, nearPlane, farPlane);
}

glm::mat4 Camera::view() const
{
	return orientation() * glm::translate(glm::mat4(), -position);
}

//
glm::mat4 Camera::orthoProjection() const
{
	return glm::ortho(
		0.0f,
		static_cast<float>(1366),
		static_cast<float>(768),
		0.0f,
		nearPlane,
		farPlane);
}

glm::mat4 Camera::orthoMatrix() const
{
	return orthoProjection() * view();
}