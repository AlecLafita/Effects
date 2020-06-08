#include "Model.h"
#include "IModelLoader.h"
#include "InterfacesFactory.h"
#include <memory>

namespace effectsEngine
{
	Model::Model(const std::string& aPath)
	{
		std::unique_ptr<IModelLoader> modelLoader = InterfacesFactory::CreateModelLoader(aPath);
		mMeshes = modelLoader->GetMeshes();//TODO avoid this copy,, should return the meshes directly
	}

	Model::~Model()
	{

	}

	void Model::Init()
	{
		for (Mesh& currentMesh : mMeshes)
		{
			currentMesh.Init();
		}
	}

	void Model::Draw(ShaderProgram& aShaderProgram)
	{
		for (auto& mesh : mMeshes)
		{
			mesh.Draw(aShaderProgram);
		}
	}
}