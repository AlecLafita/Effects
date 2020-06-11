#include "Model.h"
#include "IModelLoader.h"
#include "InterfacesFactory.h"
#include <memory>

namespace effectsEngine
{
	Model::Model(const std::string& aPath)
	{
		InterfacesFactory::GetModelLoader().ReadModel(aPath, mMeshes);
	}

	Model::~Model()
	{

	}

	void Model::Init()
	{
		int count = 0;
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