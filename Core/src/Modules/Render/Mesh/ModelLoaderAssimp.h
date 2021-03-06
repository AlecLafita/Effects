#ifndef EFFECTS_ENGINE_MODEL_LOADER_ASSIMP
#define EFFECTS_ENGINE_MODEL_LOADER_ASSIMP

#include "IModelLoader.h"
#include <assimp/material.h>
#include "TextureCommon.h"
#include "MeshCommon.h"

struct aiNode;
struct aiScene;
struct aiMesh;

namespace effectsEngine
{
	/**
	 * Implementation for a model loader ussing assimp library.
	 */
	class ModelLoaderAssimp : public IModelLoader
	{
	public:
		/**
		 * Constructor.
		 */
		ModelLoaderAssimp() = default;

		/**
		 * Destructor.
		 */
		virtual ~ModelLoaderAssimp() = default;

		/**
		 * Loads a model from a file. Textures are also loaded.
		 * \param aPath Path where the model is located.
		 * \param aMesh Container where the result meshes are being stored. 
		 */
		virtual void ReadModel(const std::string& aPath, std::vector<Mesh>& aMesh) override;

	private:

		/**
		 * Processes an assimp scene node.
		 * \param aScene assimp scene.
		 * \param aNode Current node no process.
		 * \param aMeshResult Container where the result meshes are being stored. 
		 */
		void ProcessNode(const aiScene& aScene, aiNode& aNode, std::vector<Mesh>& aMeshResult);

		/**
		 * Adds an assimp mesh to the meshes result.
		 * \param aScene assimp scene.
		 * \param aMesh Current assimp mesh.
		 * \param aMeshResult Container where the result meshes are being stored. 
		 */
		void AddMesh(const aiScene& aScene, aiMesh& aMesh, std::vector<Mesh>& aMeshResult);

		/**
		 * Loads the textures from a assim type material.
		 * \param aMat assimp material to check.
		 * \param aAssimpType assim texture type to check.
		 * \param aTextureType effectsEngine texture type.
		 * \param aTextures Container where the result textures will be stored.
		 */
		void LoadMaterialTextures(const aiMaterial& aMat, aiTextureType aAssimpType, textureCommon::eTextureType aTextureType, meshCommon::tTexturesTypesContainer& aTextures) const;

		std::string mPath;			///< Path of the current model being loaded.
	};
}

#endif
