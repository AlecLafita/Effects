#include "Model.h"
#include "IModelLoader.h"
#include "InterfacesFactory.h"
#include <memory>

namespace effectsEngine
{
	Model::Model(const std::string& aPath)
	{
		mMeshes = InterfacesFactory::GetModelLoader().ReadModel(aPath);
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