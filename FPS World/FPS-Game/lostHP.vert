#version 330 core

uniform mat4 model;

layout(location = 0) in vec3 vert;

void main()
{
	gl_Position = model * vec4(vert, 1);
}