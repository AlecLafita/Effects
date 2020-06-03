#ifndef EFFECT_ENGINE_EFFECTS_ENGINE
#define EFFECT_ENGINE_EFFECTS_ENGINE

#include <vector>
#include "ModulesCommon.h"
#include "ModulesManager.h"

namespace effectsEngine
{
	class IModule;

	/**
	* Represents the main application.
	*/
	class EffectsEngine
	{
	public:
		/**
		 * Constructor.
		 */
		EffectsEngine();

		/**
		 * Destructor.
		 */
		~EffectsEngine();

		/**
		 * Adds a module to the engine.
		 * \param aModule Identifier of the module to add.
		 */
		void AddModule(eModule aModule);

		/**
		 * Initializes the engine.
		 * \return True if everthing ok.
		 */
		bool Init();

		/**
		 * Updates the engine.
		 * \param aDeltaTime Time since last update.
		 * \return True if everthing ok.
		 */
		bool Update(float aDeltaTime);

		/**
		 * Cleans the engine.
		 */
		void Clean();

	private:
		ModulesManager				mModulesManager; //!< Manager for the modules of the engine.
	};

}

#endif