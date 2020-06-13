#ifndef EFFECTS_ENGINE_MESH_COMMON
#define EFFECTS_ENGINE_MESH_COMMON

#include <vector>
#include <string>
#include <memory>
#include <glm/glm.hpp>
#include "TextureCommon.h"

namespace effectsEngine
{
	class Texture;

	namespace meshCommon
	{
		/**
		 * Struct defined for the vertex properties.
		 */
		struct sVertex
		{
			glm::vec3 Position;
			glm::vec3 Normal;
			glm::vec2 TexCoords;
		};
		typedef std::vector<sVertex>					tVerticesContainer;		///< Type defined for a container of vertices.
		typedef std::vector<unsigned int>				tIndicesContainer;		///< Type defined for a container of vertices indices.

		/**
		 * Struct defined for the texture along its type used by a mesh.
		 */
		struct sTextureType
		{
			sTextureType(const std::shared_ptr<Texture>& aTexture, textureCommon::eTextureType aType) :
				Texture(aTexture),
				Type(aType)
			{}
			
			std::shared_ptr<Texture> Texture;
			textureCommon::eTextureType Type;
		};
		typedef std::vector<sTextureType>				tTexturesTypesContainer;	///< Type defined for a container of sTextureType.

	}
}

#endif
