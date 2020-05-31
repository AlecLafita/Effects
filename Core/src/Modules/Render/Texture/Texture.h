#ifndef EFFECTS_ENGINE_TEXTURE
#define EFFECTS_ENGINE_TEXTURE

#include <string>

namespace effectsEngine
{
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
		 * 
		 */
		void Use() const;

	private:
		unsigned int		mId;			///< Id of the texture.
	};
}

#endif
