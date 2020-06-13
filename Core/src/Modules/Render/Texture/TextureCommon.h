#ifndef EFFECTS_ENGINE_TEXTURE_COMMON
#define EFFECTS_ENGINE_TEXTURE_COMMON

namespace effectsEngine
{

	namespace textureCommon
	{
		/**
		 * Enumeration for the different texture types
		 */
		enum class eTextureType
		{
			Specular,
			Diffuse,
			Normal
		};


		static std::string GetUniformNameFromType(eTextureType aType)
		{
			switch (aType)
			{
			case eTextureType::Specular: return "uTextureSpecular";
			case eTextureType::Diffuse: return "uTextureDiffuse";
			case eTextureType::Normal: return "uTextureNormal";
			}
		}
	}
}

#endif