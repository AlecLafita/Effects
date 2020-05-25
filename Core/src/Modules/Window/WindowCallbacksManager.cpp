#include "WindowCallbacksManager.h"
#include <GLFW/glfw3.h>

namespace effectsEngine
{
	WindowCallbacksManager::WindowCallbacksManager()
	{
	}

	WindowCallbacksManager::~WindowCallbacksManager()
	{

	}

	void WindowCallbacksManager::Resize(int aWidth, int aHeight)
	{
		glViewport(0, 0, aWidth, aHeight);
	}
}
