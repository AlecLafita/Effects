#ifndef EFFECTS_ENGINE_IMAGE_IMPLEMENTATION_STB_IMAGE
#define EFFECTS_ENGINE_IMAGE_IMPLEMENTATION_STB_IMAGE

#include "IImageImplementation.h"

namespace effectsEngine
{
	/**
	 * Implementation for a image using the library stb_image.
	 */
	class ImageImplementationSTBImage : public IImageImplementation
	{
	public:
		/**
		 * Constructor.
		 */
		ImageImplementationSTBImage();

		/**
		 * Destructor.
		 */
		~ImageImplementationSTBImage();

		/**
		 * Loads an image from its path.
		 * \param aPath Path where the image is.
		 */
		virtual void Load(const std::string& aPath) override;

		/**
		 * Gets the data of the image.
		 * \return Image data.
		 */
		virtual unsigned char* GetData() const override;
		/**
		 * Gets the width of the image.
		 * \return Image width.
		 */
		virtual uint16_t GetWidth() const override;

		/**
		 * Gets the height of the image.
		 * \return Image height.
		 */
		virtual uint16_t GetHeight() const override;

		/**
		 * Gets the number of channels of the image.
		 * \return Image channels number.
		 */
		virtual uint8_t GetChannelsNumber() const override;

	private:
		unsigned char*	mData;				///< Data of the image.
		int				mWidth;				///< Width of the image.
		int				mHeight;			///< Height of the image.
		int				mChannelsNumber;	///< Number of channels of the image.
	};
}

#endif