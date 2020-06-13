#ifndef EFFECTS_ENGINE_TEXTURES_MANAGER
#define EFFECTS_ENGINE_TEXTURES_MANAGER

#include <unordered_map>
#include <memory>
#include "Singleton.h"

namespace effectsEngine
{
	class Texture;

	class TexturesManager : public Singleton<TexturesManager>
	{
	public:
		friend class Singleton<TexturesManager>;


		std::shared_ptr<Texture> GetResource(const std::string& aTexturePath);

	private:
		/**
		 * Private constructor to achieve singleton pattern.
		 */
		TexturesManager();

		std::unordered_map<std::string, std::shared_ptr<Texture>>	mTextures;		///< Different textures resources mapped by texture path.
	};
}

#endif