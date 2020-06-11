#include "InterfacesFactory.h"
#include "ImageImplementationSTBImage.h"
#include "ModelLoaderAssimp.h"

namespace effectsEngine
{
	InterfacesFactory::InterfacesFactory()
	{
	}

	IModelLoader& InterfacesFactory::GetModelLoader()
	{
		return ModelLoaderAssimp::GetInstance();
	}

	std::unique_ptr<IImageImplementation> InterfacesFactory::CreateImageImplementation()
	{
		return std::make_unique<ImageImplementationSTBImage>();
	}
}
