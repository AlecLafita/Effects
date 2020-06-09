#ifndef EFFECTS_ENGINE_TEXTURE
#define EFFECTS_ENGINE_TEXTURE

#include <string>
#include "TextureCommon.h"

namespace effectsEngine
{
	class ShaderProgram;

	/**
	 * Class for handle a texture.
	 */
	class Texture
	{
	public:

		/**
		 * Constructor.
		 * \param aPath Path where the texture file is located.
		 * \param aTextureType Type of the texture.
		 */
		Texture(std::string&& aPath, textureCommon::eTextureType aTextureType);

		/**
		 * Destructor.
		 */
		~Texture();

		/**
		 * Uses the texture to draw. Must be called before drawing.
		 * \param aShaderProgram Shader that will use the texture.
		 * \param aUniformName Uniform name for the sampler thes shader uses.
		 * \param aTextureUnit Texture unit to use.
		 * \precondition Parameter shader program is being used.
		 */
		void Use(ShaderProgram& aShaderProgram, const std::string& aUniformName, uint8_t aTextureUnit) const;

		/**
		 * Gets the type of the texture.
		 * \return Enumeration with the texture type.
		 */
		textureCommon::eTextureType GetTextureType() const;

	private:
		unsigned int						mId;			///< Id of the texture.
		const textureCommon::eTextureType	mTextureType;	///< Type of the texture.
	};
}

#endif
