#ifndef EFFECTS_ENGINE_MODEL_LOADER_ASSIMP
#define EFFECTS_ENGINE_MODEL_LOADER_ASSIMP

#include "IModelLoader.h"
#include "Singleton.h"
#include "TextureCommon.h"
#include <assimp/material.h>

struct aiNode;
struct aiScene;
struct aiMesh;

namespace effectsEngine
{
	/**
	 * Implementation for a singleton model loader ussing assimp library.
	 */
	class ModelLoaderAssimp : public IModelLoader, public Singleton<ModelLoaderAssimp>
	{
		friend class Singleton <ModelLoaderAssimp>;

	public:

		virtual const std::vector<Mesh> ReadModel(const std::string& aPath) override;

		virtual ~ModelLoaderAssimp() = default;
	private:
		ModelLoaderAssimp() = default;

		void ProcessNode(const aiScene& aScene, aiNode& aNode, std::vector<Mesh>& aMeshResult);

		Mesh TransformMesh(const aiScene& aScene, aiMesh& aMesh);

		void LoadMaterialTextures(const aiMaterial& aMat, aiTextureType aAssimpType, textureCommon::eTextureType aTextureType, Mesh::tTexturesContainer& aTextures) const;

		std::string mPath;
	};
}

#endif
