#version 330 core

//layout(location = 0) in vec3 vertexPosition_modelspace;

uniform mat4 camera;
uniform mat4 model;

layout(location = 0) in vec3 vert;

void main()
{
    //gl_Position.xyz = vertexPosition_modelspace;
    //gl_Position.w = 1.0;

	gl_Position = camera * model * vec4(vert, 1);
}