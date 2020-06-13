#include "InterfacesFactory.h"
#include "ImageImplementationSTBImage.h"

namespace effectsEngine
{
	InterfacesFactory::InterfacesFactory()
	{
	}

	std::unique_ptr<IImageImplementation> InterfacesFactory::CreateImageImplementation()
	{
		return std::make_unique<ImageImplementationSTBImage>();
	}
}
