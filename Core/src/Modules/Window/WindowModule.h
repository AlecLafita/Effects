#ifndef EFFECTS_ENGINE_WINDOW_MODULE
#define EFFECTS_ENGINE_WINDOW_MODULE

#include "IModule.h"
#include "WindowCallbacksManager.h"

namespace effectsEngine
{
	/**
	 * Class for the window module.
	 */
	class WindowModule : public IModule
	{
	public:
		/**
		 * Constructor.
		 */
		WindowModule();

		/**
		 * Destructor.
		 */
		virtual ~WindowModule();

		/**
		 * Initializes the module.
		 * \return True if everthing ok.
		 */
		bool Init() override;

		/**
		 * Updates the module.
		 * \param aDeltaTime Time since last update.
		 * \return True if everthing ok.
		 */
		bool Update(float aDeltaTime) override;

		/**
		 * Cleans the module.
		 */
		void Clean() override;

	private:
		WindowCallbacksManager			mWindowCallbacksManager; ///< Instance to manage library window callbacks.
	};
}

#endif