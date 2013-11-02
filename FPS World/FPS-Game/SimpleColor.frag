#version 330 core

uniform vec3 m_color;
out vec3 color;

void main()
{
	color = m_color;
}