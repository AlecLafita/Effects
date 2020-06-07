#include "Model.h"
#include "IModelLoader.h"
#include "InterfacesFactory.h"
#include <memory>

namespace effectsEngine
{
	Model::Model(const std::string& aPath)
	{
		std::unique_ptr<IModelLoader> modelLoader = InterfacesFactory::CreateModelLoader();
	}

	Model::~Model()
	{

	}

	void Model::Draw(ShaderProgram& aShaderProgram)
	{
		for (auto& mesh : mMeshes)
		{
			mesh.Draw(aShaderProgram);
		}
	}
}