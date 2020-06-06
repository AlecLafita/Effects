#ifndef EFFECTS_ENGINE_TEXTURE
#define EFFECTS_ENGINE_TEXTURE

#include <string>

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
		 */
		Texture(std::string&& aPath);

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

	private:
		unsigned int		mId;			///< Id of the texture.
	};
}

#endif
