#version 330 core

uniform mat4 model;
uniform mat4 camera;

layout(location = 0) in vec3 vert;
layout(location = 1) in vec2 vertTexCoord;
layout(location = 2) in vec3 normals;

out vec2 fragTexCoord;
out vec3 fragVert;
out vec3 fragNormal;

void main() 
{
    // Pass the tex coord straight through to the fragment shader
    //fragTexCoord = vertTexCoord;
	fragVert = vert;
	fragNormal = normals;
    
    gl_Position = camera * model * vec4(vert, 1);
}

