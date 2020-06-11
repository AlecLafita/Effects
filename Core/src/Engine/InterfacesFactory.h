#ifndef EFFECTS_ENGINE_INTERFACES_FACTORY
#define EFFECTS_ENGINE_INTERFACES_FACTORY

#include <memory>
#include <string>
#include "Singleton.h"

namespace effectsEngine
{
	class IModelLoader;
	class IImageImplementation;

	/**
	 * Singleton factory to agrupate the creation of the various interfaces specializations across the engine.
	 */
	class InterfacesFactory : public Singleton<InterfacesFactory>
	{
		friend class Singleton<InterfacesFactory>;
	public:

		/**
		 * Gets an instance for the model loader implementation.
		 * \return IModelLoader specialization instance.
		 */
		static IModelLoader& GetModelLoader(); //TODO this should be in some service locator, not in a factory!
	
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
