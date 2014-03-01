#pragma once

#include "Renderer.h"

class EventHandler
{
private:
	EventHandler(const EventHandler& ev);
	EventHandler& operator=(const EventHandler& ev);

	Renderer* m_renderer;

public:
	EventHandler();

	EventHandler(Renderer* renderer);

	void handleEvents();

	void handleKeyboard();

	void handleMouse();
	
	/**
	 * @brief - Callback function for registering keyboard presses
	 * @param key    - gets the pressed key
	 * @param action - registers the action (GLFW_PRESS or GLFW_RELEASE)
	 * @reference    - glfwSetKeyCallback()
	*/
	static void GLFWCALL keyboardCallback(int key, int action);

	/**
	 * @brief - Callback function for registering mouse presses
	 * @param key    - gets the pressed key
	 * @param action - registers the action (GLFW_PRESS or GLFW_RELEASE)
	 * @reference	 - glfwSetMouseButtonCallback
	 */
	static void GLFWCALL mouseKeyCallback(int key, int action);
};