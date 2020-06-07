#include "InterfacesFactory.h"
#include "ImageImplementationSTBImage.h"
#include "ModelLoaderAssimp.h"

namespace effectsEngine
{
	InterfacesFactory::InterfacesFactory()
	{
	}
	
	InterfacesFactory& InterfacesFactory::GetInstance()
	{
		static InterfacesFactory mInstance;

		return mInstance;
	}

	std::unique_ptr<IModelLoader> InterfacesFactory::CreateModelLoader()
	{
		return std::make_unique<ModelLoaderAssimp>();
	}

	std::unique_ptr<IImageImplementation> InterfacesFactory::CreateImageImplementation()
	{
		return std::make_unique<ImageImplementationSTBImage>();
	}
}
