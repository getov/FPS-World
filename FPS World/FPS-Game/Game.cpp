#include <GL\glew.h>
#include <GL\glfw.h>

#include <iostream>

#include "Application.h"

using namespace std;

int main()
{
	Application& app = Application::Instance();

	app.run();

	return EXIT_SUCCESS;
}