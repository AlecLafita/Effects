#ifndef EFFECTS_ENGINE_WINDOW_MODULE
#define EFFECTS_ENGINE_WINDOW_MODULE

#include "IModule.h"

struct GLFWwindow;

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

		/**
		 * Resizes the window.
		 * \param aWindow Window instance.
		 * \param aWidth Width to resize.
		 * \param aHeight Height to resize.
		 */
		static void Resize(GLFWwindow* aWindow, int aWidth, int aHeight); //TODO to very nice being static

	private:
		GLFWwindow*			mWindow; ///< Window instance.
	};
}

#endif