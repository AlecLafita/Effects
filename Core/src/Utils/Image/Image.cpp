#include "Image.h"

#include "ImageImplementationSTBImage.h"

namespace effectsEngine
{
	Image::Image() :
		mImageImplementation(std::make_unique<ImageImplementationSTBImage>())
	{
	}
	
	Image::~Image()
	{
	}

	void Image::Load(const std::string&& aPath)
	{
		mImageImplementation->Load(std::move(aPath));
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