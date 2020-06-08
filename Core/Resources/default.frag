#version 330 core
in vec2 texCoord;

uniform sampler2D uniformTexture1;

out vec4 FragColor;

void main()
{
   FragColor = texture(uniformTexture1, texCoord);
}