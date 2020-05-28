#ifndef EFFECTS_ENGINE_SHADER_COMMON
#define EFFECTS_ENGINE_SHADER_COMMON

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace effectsEngine
{
	/**
	 * Enumeration for the different shader types.
	 */
	enum class eShaderType
	{
		Vertex,
		Fragment
	};
}

#endif