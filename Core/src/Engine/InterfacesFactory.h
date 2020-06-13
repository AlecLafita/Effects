#ifndef EFFECTS_ENGINE_INTERFACES_FACTORY
#define EFFECTS_ENGINE_INTERFACES_FACTORY

#include <memory>
#include <string>
#include "Singleton.h"

namespace effectsEngine
{
	class IImageImplementation;

	/**
	 * Singleton factory to agrupate the creation of the various interfaces specializations across the engine.
	 */
	class InterfacesFactory : public Singleton<InterfacesFactory>
	{
		friend class Singleton<InterfacesFactory>;
	public:
	
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
