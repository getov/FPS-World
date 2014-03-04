#include "EventHandler.h"

EventHandler::EventHandler()
{
}

EventHandler::EventHandler(Renderer* renderer)
	: m_renderer(renderer)
{
}

void EventHandler::handleEvents()
{
	handleMouse();
	handleKeyboard();
}

void EventHandler::handleKeyboard()
{
	if (glfwGetKey(GLFW_KEY_DEL) == GLFW_PRESS)
	{
		m_renderer->removeLastGeometry();
	}
}

void EventHandler::handleMouse()
{
	if (glfwGetMouseButton(GLFW_MOUSE_BUTTON_LEFT == GLFW_PRESS))
	{
		m_renderer->createBox();
	}

	if (glfwGetMouseButton(GLFW_MOUSE_BUTTON_RIGHT == GLFW_PRESS))
	{
		m_renderer->createBoxNoTex();
	}
}

void GLFWCALL EventHandler::keyboardCallback(int key, int action)
{
}

void GLFWCALL EventHandler::mouseKeyCallback(int key, int action)
{
}