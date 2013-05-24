#version 330 core

uniform mat4 model;

layout(location = 0) in vec3 vert;
layout(location = 1) in vec2 vertTexCoord;

out vec2 fragTexCoord;

void main() {
    // Pass the tex coord straight through to the fragment shader
    fragTexCoord = vertTexCoord;
    
    gl_Position = model * vec4(vert, 1);
}

