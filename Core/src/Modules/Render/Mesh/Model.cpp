#include "Model.h"
#include "IModelLoader.h"
#include <memory>
#include "ServiceLocator.h"

namespace effectsEngine
{
	Model::Model(const std::string& aPath)
	{
		ServiceLocator<IModelLoader>::GetService().ReadModel(aPath, mMeshes);
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