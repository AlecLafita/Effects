#ifndef EFFECTS_ENGINE_PARTICLE
#define EFFECTS_ENGINE_PARTICLE

#include <glm/glm.hpp>

namespace effectsEngine
{
	/**
	* Particle info.
	*/
	struct sParticle
	{
		glm::vec3 Position;
		glm::vec3 OldPosition;
		glm::vec3 Velocity;
		uint16_t Energy;
		glm::vec2 Size;
	};
}

#endif
