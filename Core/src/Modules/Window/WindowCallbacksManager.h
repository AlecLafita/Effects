#ifndef EFFECTS_ENGINE_WINDOW_CALLBACK_MANAGER
#define EFFECTS_ENGINE_WINDOW_CALLBACK_MANAGER

namespace effectsEngine
{
	/**
	 * Class for manage the window callbacks.
	 */
	class WindowCallbacksManager
	{
	public:
		/**
		 * Constructor.
		 */
		WindowCallbacksManager();

		/**
		 * Destructor.
		 */
		virtual ~WindowCallbacksManager();

		/**
		 * Resizes the window.
		 * \param aWidth Width to resize.
		 * \param aHeight Height to resize.
		 */
		void Resize(int aWidth, int aHeight);

	};
}

#endif