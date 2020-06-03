#ifndef EFFECTS_ENGINE_MODULES_COMMON
#define EFFECTS_ENGINE_MODULES_COMMON

namespace effectsEngine
{
	/**
	 * Enumeration with the different modules.
	 */
	enum class eModule
	{
		Window, //Window must be the first module as it initializes opengl!
		Camera,
		Render
	};
}

#endif
