#ifndef EFFECTS_ENGINE_MODEL_LOADER_ASSIMP
#define EFFECTS_ENGINE_MODEL_LOADER_ASSIMP

#include "IModelLoader.h"
#include <string>
#include <vector>
#include "TextureCommon.h"
#include <assimp/material.h>

struct aiNode;
struct aiScene;
struct aiMesh;

namespace effectsEngine
{
	//TODO maybe this class should be static, and each time a model asks for load, reset all the members, so we don't have to be tied with one loader instance for each model

	/**
	 * Implementation for a model loader ussing assimp library.
	 */
	class ModelLoaderAssimp : public IModelLoader
	{
	public:
		ModelLoaderAssimp(const std::string& aPath);

		virtual ~ModelLoaderAssimp();
	private:

		void ProcessNode(const aiScene& aScene, aiNode& aNode);

		Mesh TransformMesh(const aiScene& aScene, aiMesh& aMesh);

		void LoadMaterialTextures(const aiMaterial& aMat, aiTextureType aAssimpType, textureCommon::eTextureType aTextureType, Mesh::tTexturesContainer& aTextures) const;
	};
}

#endif
