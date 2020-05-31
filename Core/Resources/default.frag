#version 330 core
in vec3 colour;
in vec2 texCoord;

uniform vec4 uniformColor;
uniform sampler2D uniformTexture1;

out vec4 FragColor;

void main()
{
   //FragColor = vec4(0.0f, 0.5f, 1.0f, 1.0f);
   //FragColor = uniformColor;
   //FragColor = vec4(colour, 1.0f);
   FragColor = texture(uniformTexture1, texCoord) * vec4(colour, 1.0);
}