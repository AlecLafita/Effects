#ifndef EFFECTS_ENGINE_MODULES_MANAGER
#define EFFECTS_ENGINE_MODULES_MANAGER

#include <memory>
#include <map>
#include "ModulesCommon.h"

namespace effectsEngine
{
	class IModule;

	/**
	 * Class to handle the differents modules.
	 */
	class ModulesManager
	{
	public:
		/**
		 * Gets a module from its identifier.
		 * \tparam TModule Type of the module to obtain.
		 * \param aModule Module identifier.
		 * \return Module corresponding to the identifier.
		 */
		template<typename TModule>
		static TModule& GetModule(eModule aModule)
		{
			auto ModuleIterator = mModules.find(aModule);
			if (ModuleIterator == mModules.end())
			{
				//TODO throw
			}
			return *(static_cast<TModule*>(ModuleIterator->second.get()));
		}

	private:
		friend class EffectsEngine;		///< Besides EffectsEngine class, this class must only be used to get the various modules.

		typedef std::map<eModule, std::unique_ptr<IModule>> tModules;	///< Type for a container of modules references.

		/**
		 * Constructor.
		 */
		ModulesManager();

		/**
		 * Destructor.
		 */
		~ModulesManager();

		/**
		 * Creates a new module.
		 * \param aModule Identifier of the module to add.
		 */
		void AddModule(eModule aModule);

		/**
		 * Obtains the modules.
		 * \return Reference to the current modules
		 */
		const tModules& GetModules() const;


		static tModules		mModules;				///< Map with the available modules.
	};
}

#endif
