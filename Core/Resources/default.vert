#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColour;
layout (location = 2) in vec2 aTexCoord;

uniform mat4 uModelMatrix;
uniform mat4 uViewMatrix;
uniform mat4 uProjectionMatrix;

out vec3 colour;
out vec2 texCoord;

void main()
{
    gl_Position = uProjectionMatrix*uViewMatrix*uModelMatrix*vec4(aPos, 1.0);
    colour = aColour;
    texCoord = aTexCoord;
}