#include "ModelLoaderAssimp.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <iostream>
#include "Mesh.h"
#include "Texture.h"
#include "TexturesManager.h"

namespace effectsEngine
{
	void ModelLoaderAssimp::ReadModel(const std::string& aPath, std::vector<Mesh>& aMesh)
	{
		mPath = aPath.substr(0, aPath.find_last_of('/'));

		Assimp::Importer importer;
		const aiScene* pScene = importer.ReadFile(aPath.c_str(),
			aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs | aiProcess_JoinIdenticalVertices);
		if (pScene == nullptr || pScene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || pScene->mRootNode == nullptr)
		{
			std::cout << "Error loading model" << importer.GetErrorString() << std::endl;
		}
		else
		{
			std::cout << "Model file read" << importer.GetErrorString() << std::endl;
			aMesh.reserve(pScene->mNumMeshes);
			ProcessNode(*pScene, *(pScene->mRootNode), aMesh);
		}

		mPath = "";
	}

	void ModelLoaderAssimp::ProcessNode(const aiScene& aScene, aiNode& aNode, std::vector<Mesh>& aMeshResult)
	{
		for (unsigned int currentMeshIndex = 0U; currentMeshIndex < aNode.mNumMeshes; currentMeshIndex++)
		{
			aiMesh* currentMesh = aScene.mMeshes[aNode.mMeshes[currentMeshIndex]];		
			AddMesh(aScene, *currentMesh, aMeshResult);
		}

		for (unsigned int currentChildIndex = 0U; currentChildIndex < aNode.mNumChildren; ++currentChildIndex)
		{
			ProcessNode(aScene, *aNode.mChildren[currentChildIndex], aMeshResult);
		}
	}

	void ModelLoaderAssimp::AddMesh(const aiScene& aScene, aiMesh& aMesh, std::vector<Mesh>& aMeshResult)
	{
		meshCommon::tVerticesContainer vertices(aMesh.mNumVertices);
		for (unsigned int currentVertexIndex = 0U; currentVertexIndex < aMesh.mNumVertices; ++currentVertexIndex)
		{
			const aiVector3D& vertexPosition = aMesh.mVertices[currentVertexIndex];
			const aiVector3D& vertexNormal = aMesh.mNormals[currentVertexIndex];
			glm::vec2 vertexUV(0.0f);
			if (aMesh.mTextureCoords[0U] != nullptr)
			{
				vertexUV.x = aMesh.mTextureCoords[0U][currentVertexIndex].x;
				vertexUV.y = aMesh.mTextureCoords[0U][currentVertexIndex].y;
			}
			meshCommon::sVertex vertex {
				glm::vec3(vertexPosition.x, vertexPosition.y, vertexPosition.z),
				glm::vec3(vertexNormal.x, vertexNormal.y, vertexNormal.z),
				vertexUV
			};
			vertices.at(currentVertexIndex) = vertex;
		}

		meshCommon::tIndicesContainer indices(3U * aMesh.mNumFaces);//3 due to aiProcess_Triangulate while loading
		for (unsigned int currentFaceIndex = 0U; currentFaceIndex < aMesh.mNumFaces; ++currentFaceIndex)
		{
			const aiFace& face = aMesh.mFaces[currentFaceIndex];
			for (unsigned int currentIndexFaceIndex = 0U; currentIndexFaceIndex < face.mNumIndices; ++currentIndexFaceIndex)
			{
				indices.at(3U * currentFaceIndex + currentIndexFaceIndex) = face.mIndices[currentIndexFaceIndex];
			}
		}
		
		meshCommon::tTexturesTypesContainer textures;
		if (aMesh.mMaterialIndex >= 0U)
		{
			const aiMaterial& material = *aScene.mMaterials[aMesh.mMaterialIndex];
			LoadMaterialTextures(material, aiTextureType_DIFFUSE, textureCommon::eTextureType::Diffuse, textures);
			LoadMaterialTextures(material, aiTextureType_SPECULAR, textureCommon::eTextureType::Specular, textures);
			LoadMaterialTextures(material, aiTextureType_NORMALS, textureCommon::eTextureType::Normal, textures);
		}
		
		aMeshResult.emplace_back(std::move(vertices), std::move(indices), std::move(textures));
	}

	void ModelLoaderAssimp::LoadMaterialTextures(const aiMaterial& aMat, aiTextureType aAssimpType, textureCommon::eTextureType aTextureType, meshCommon::tTexturesTypesContainer& aTextures) const
	{
		size_t totalTextures = aMat.GetTextureCount(aAssimpType);
		for (unsigned int currentTextureIndex = 0; currentTextureIndex < totalTextures; ++currentTextureIndex)
		{
			aiString path;
			if (aMat.GetTexture(aAssimpType, currentTextureIndex, &path) == aiReturn_SUCCESS)
			{
				aTextures.emplace_back(TexturesManager::GetInstance().GetResource(mPath + '/' + path.C_Str()), aTextureType);
			}
		}
	}
}