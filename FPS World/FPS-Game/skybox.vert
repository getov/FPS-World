#version 330 core

uniform mat4 camera;
uniform mat4 model;

layout(location = 0) in vec3 vert;
layout(location = 1) in vec3 vertNormal;
layout(location = 2) in vec2 vertTexCoord;

out vec3 fragVert;
out vec3 fragNormal;
out vec2 fragTexCoord;

void main()
{
	fragTexCoord = vertTexCoord;
	fragNormal = vertNormal;
    fragVert = vert;

	gl_Position = camera * model * vec4(vert, 1);
}