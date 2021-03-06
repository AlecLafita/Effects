#include "ImageImplementationSTBImage.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <iostream>

namespace effectsEngine
{
	ImageImplementationSTBImage::ImageImplementationSTBImage() : 
		mData(nullptr),
		mHeight(0U),
		mWidth(0U),
		mChannelsNumber(0U)
	{
	}

	ImageImplementationSTBImage::~ImageImplementationSTBImage()
	{
		stbi_image_free(mData);
	}

	void ImageImplementationSTBImage::Load(const std::string& aPath)
	{
		stbi_set_flip_vertically_on_load(true);
		mData = stbi_load(aPath.c_str(), &mWidth, &mHeight, &mChannelsNumber, 0);
		if (mData == nullptr)
		{
			std::cout << "Image " << aPath << "could not be loaded" << std::endl;
			//TODO throw exception
		}
	}
	unsigned char* ImageImplementationSTBImage::GetData() const
	{
		return mData;
	}
	uint16_t ImageImplementationSTBImage::GetWidth() const
	{
		return static_cast<uint16_t>(mWidth);
	}
	uint16_t ImageImplementationSTBImage::GetHeight() const
	{
		return static_cast<uint16_t>(mHeight);
	}
	uint8_t ImageImplementationSTBImage::GetChannelsNumber() const
	{
		return static_cast<uint8_t>(mChannelsNumber);
	}
}