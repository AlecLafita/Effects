#include "Image.h"
#include "IImageImplementation.h"
#include "InterfacesFactory.h"

namespace effectsEngine
{
	Image::Image() :
		mImageImplementation(InterfacesFactory::GetInstance().CreateImageImplementation())
	{
	}
	
	Image::~Image()
	{
	}

	void Image::Load(const std::string& aPath)
	{
		mImageImplementation->Load(aPath);
	}
	
	unsigned char* Image::GetData() const
	{
		return mImageImplementation->GetData();
	}

	uint16_t Image::GetWidth() const
	{
		return mImageImplementation->GetWidth();
	}
	uint16_t Image::GetHeight() const
	{
		return mImageImplementation->GetHeight();
	}
	uint8_t Image::GetChannelsNumber() const
	{
		return mImageImplementation->GetChannelsNumber();
	}
}