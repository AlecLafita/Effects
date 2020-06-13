#version 330 core
in vec2 texCoord;

uniform sampler2D uTextureDiffuse0;

out vec4 FragColor;

void main()
{
   FragColor = texture(uTextureDiffuse0, texCoord);
}