#include "TexturesManager.h"
#include "Texture.h"

namespace effectsEngine
{
	TexturesManager::TexturesManager() :
		mTextures()
	{
	}

	std::shared_ptr<Texture> TexturesManager::GetResource(const std::string& aTexturePath)
	{
		const auto& texturesIterator = mTextures.find(aTexturePath);
		if (texturesIterator != mTextures.end())
		{
			return texturesIterator->second;
		}

		auto newTexture = std::make_shared<Texture>(aTexturePath);
		mTextures.emplace(aTexturePath, newTexture);
		return newTexture;
	}
}