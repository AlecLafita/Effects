#include "ModelLoaderAssimp.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <iostream>

namespace effectsEngine
{
	ModelLoaderAssimp::ModelLoaderAssimp(const std::string& aPath) : 
		IModelLoader()
	{
		Assimp::Importer importer;
		const aiScene* pScene = importer.ReadFile(aPath.c_str(),
			aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs | aiProcess_JoinIdenticalVertices);
		if (pScene == nullptr || pScene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || pScene->mRootNode == nullptr)
		{
			std::cout << "ERROR::ASSIMP::" << importer.GetErrorString() << std::endl;
		}
		else
		{
			mMeshes.reserve(pScene->mNumMeshes);
			ProcessNode(*pScene, *(pScene->mRootNode));
		}
	}

	ModelLoaderAssimp::~ModelLoaderAssimp()
	{
	}

	void ModelLoaderAssimp::ProcessNode(const aiScene& aScene, aiNode& aNode)
	{
		for (unsigned int currentMeshIndex = 0U; currentMeshIndex < aNode.mNumMeshes; currentMeshIndex++)
		{
			aiMesh* currentMesh = aScene.mMeshes[aNode.mMeshes[currentMeshIndex]];		
			mMeshes.push_back(TransformMesh(aScene, *currentMesh));
		}

		for (unsigned int currentChildIndex = 0U; currentChildIndex < aNode.mNumChildren; ++currentChildIndex)
		{
			ProcessNode(aScene, *aNode.mChildren[currentChildIndex]);
		}
	}

	Mesh ModelLoaderAssimp::TransformMesh(const aiScene& aScene, aiMesh& aMesh)
	{
		Mesh::tVerticesContainer vertices(aMesh.mNumVertices);
		Mesh::tIndicesContainer indices;
		Mesh::tTexturesContainer textures = {};

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
			Mesh::sVertex vertex {
				glm::vec3(vertexPosition.x, vertexPosition.y, vertexPosition.z),
				glm::vec3(vertexNormal.x, vertexNormal.y, vertexNormal.z),
				vertexUV
			};
			vertices.at(currentVertexIndex) = vertex;
		}

		for (unsigned int currentFaceIndex = 0U; currentFaceIndex < aMesh.mNumFaces; ++currentFaceIndex)
		{
			const aiFace& face = aMesh.mFaces[currentFaceIndex];
			for (unsigned int currentIndexFaceIndex = 0U; currentIndexFaceIndex < face.mNumIndices; ++currentIndexFaceIndex)
			{
				indices.push_back(face.mIndices[currentIndexFaceIndex]);
			}
		}
		
		//TODO textures

		return Mesh(std::move(vertices), std::move(indices), std::move(textures));
	}
}