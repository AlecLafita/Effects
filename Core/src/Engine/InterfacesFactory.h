#ifndef EFFECTS_ENGINE_INTERFACES_FACTORY
#define EFFECTS_ENGINE_INTERFACES_FACTORY

#include <memory>
#include <string>

namespace effectsEngine
{
	class IModelLoader;
	class IImageImplementation;

	/**
	 * Singleton factory to agrupate the creation of the various interfaces specializations across the engine.
	 */
	class InterfacesFactory
	{
	public:
		/**
		 * Obtains the singleton instance.
		 * \return Singleton instance of the class.
		 */
		static InterfacesFactory& GetInstance();

		/**
		 * Delete copy constructors to achieve singleton pattern.
		 */
		InterfacesFactory(InterfacesFactory const&) = delete;
		void operator=(InterfacesFactory const&) = delete;


		/***** Factory methods*****/

		/**
		 * Creates an instance for the model loader implementation.
		 * \param aPath Path where the model is.
		 * \return IModelLoader specialization instance.
		 */
		static std::unique_ptr<IModelLoader> CreateModelLoader(const std::string& aPath);
	
		/**
		 * Creates an instance for the image implementation.
		 * \return IImageImplementation specialization instance.
		 */
		static std::unique_ptr<IImageImplementation> CreateImageImplementation();
	
	private:
		/**
		 * Private constructor to achieve singleton pattern.
		 */
		InterfacesFactory();
	};
}

#endif
