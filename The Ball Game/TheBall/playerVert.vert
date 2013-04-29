#version 330 core

uniform mat4 camera;
uniform mat4 model;

layout(location = 0) in vec3 vert;

void main()
{
	gl_Position = camera * model * vec4(vert, 1);
}