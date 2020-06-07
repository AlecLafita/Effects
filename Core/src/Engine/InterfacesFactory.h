#ifndef EFFECTS_ENGINE_INTERFACES_FACTORY
#define EFFECTS_ENGINE_INTERFACES_FACTORY

#include <memory>

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
		 * \return IModelLoader specialization instance.
		 */
		static std::unique_ptr<IModelLoader> CreateModelLoader();
	
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
