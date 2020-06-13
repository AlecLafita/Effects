#include "Texture.h"
#include "Image.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "ShaderProgram.h"

namespace effectsEngine
{
	Texture::Texture(const std::string& aPath)
	{
		glGenTextures(1, &mId);
		glBindTexture(GL_TEXTURE_2D, mId);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		Image image;
		image.Load(aPath);
		GLenum format = 0U;
		switch (image.GetChannelsNumber())
		{
			case 1: format = GL_RED; break;
			case 2: format = GL_RG; break;
			case 3: format = GL_RGB; break;
			case 4: format = GL_RGBA; break;
		}
		glTexImage2D(GL_TEXTURE_2D, 0, format, image.GetWidth(), image.GetHeight(), 0, format, GL_UNSIGNED_BYTE, image.GetData());//TODO parametrizable, 2d, 3d textures, etc
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	Texture::~Texture()
	{
		glDeleteTextures(1, &mId);
	}

	void Texture::Use(ShaderProgram& aShaderProgram, const std::string& aUniformName, uint8_t aTextureUnit) const
	{
		aShaderProgram.SetInt(aUniformName, aTextureUnit);
		glActiveTexture(GL_TEXTURE0 + aTextureUnit);
		glBindTexture(GL_TEXTURE_2D, mId);
	}
}