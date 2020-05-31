#ifndef EFFECTS_ENGINE_I_IMAGE_IMPLEMENTATION
#define EFFECTS_ENGINE_I_IMAGE_IMPLEMENTATION

#include <string>

namespace effectsEngine
{
	/**
	 * Interface for the implementation of an image.
	 */
	class IImageImplementation
	{
	public:
		/**
		 * Constructor.
		 */
		IImageImplementation() {}

		/**
		 * Destructor.
		 */
		virtual ~IImageImplementation() {}

		/**
		 * Loads an image from its path.
		 * \param aPath Path where the image is.
		 */
		virtual void Load(const std::string&& aPath) = 0;

		/**
		 * Gets the data of the image.
		 * \return Image data.
		 */
		virtual unsigned char* GetData() const = 0;

		/**
		 * Gets the width of the image.
		 * \return Image width.
		 */
		virtual uint16_t GetWidth() const = 0;

		/**
		 * Gets the height of the image.
		 * \return Image height.
		 */
		virtual uint16_t GetHeight() const = 0;
		
		/**
		 * Gets the number of channels of the image.
		 * \return Image channels number.
		 */
		virtual uint8_t GetChannelsNumber() const = 0;
	};
}

#endif