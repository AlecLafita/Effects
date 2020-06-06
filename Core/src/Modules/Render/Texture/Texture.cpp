#include "Texture.h"
#include "Image.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "ShaderProgram.h"

namespace effectsEngine
{
	Texture::Texture(std::string&& aPath)
	{
		glGenTextures(1, &mId);
		glBindTexture(GL_TEXTURE_2D, mId);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		Image image;
		image.Load(std::move(aPath));
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image.GetWidth(), image.GetHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, image.GetData());//TODO parametrizable, 2d, 3d textures, etc
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	Texture::~Texture()
	{
	}
	void Texture::Use(ShaderProgram& aShaderProgram, const std::string& aUniformName, uint8_t aTextureUnit) const
	{
		aShaderProgram.SetInt(aUniformName, aTextureUnit);
		glActiveTexture(GL_TEXTURE0 + aTextureUnit);
		glBindTexture(GL_TEXTURE_2D, mId);
	}
}