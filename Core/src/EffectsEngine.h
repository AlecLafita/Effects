#ifndef EFFECT_ENGINE_EFFECTS_ENGINE
#define EFFECT_ENGINE_EFFECTS_ENGINE

#include <vector>

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
		 * \param aModule Module to add.
		 */
		void AddModule(IModule* aModule);

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
		std::vector<IModule*>		mModules; ///< Contains the modules of the engine.
	};

}

#endif