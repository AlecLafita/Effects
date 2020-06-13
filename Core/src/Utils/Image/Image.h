#ifndef EFFECTS_ENGINE_IMAGE
#define EFFECTS_ENGINE_IMAGE

#include <memory>
#include <string>

namespace effectsEngine
{
	class IImageImplementation;

	/**
	 * Class to handle an image.
	 */
	class Image
	{
	public:
		/**
		 * Constructor.
		 */
		Image();

		/**
		 * Destructor.
		 */
		~Image(); 

		/**
		 * Loads an image from its path.
		 * \param aPath Path where the image is.
		 */
		void Load(const std::string& aPath);

		/**
		 * Gets the data of the image.
		 * \return Image data.
		 */
		unsigned char* GetData() const;

		/**
		 * Gets the width of the image.
		 * \return Image width.
		 */
		uint16_t GetWidth() const;

		/**
		 * Gets the height of the image.
		 * \return Image height.
		 */
		uint16_t GetHeight() const;

		/**
		 * Gets the number of channels of the image.
		 * \return Image channels number.
		 */	
		uint8_t GetChannelsNumber() const;

	private:
		std::unique_ptr<IImageImplementation>		mImageImplementation;	///< Implementation of image to de delegate operations.
	};
}

#endif
