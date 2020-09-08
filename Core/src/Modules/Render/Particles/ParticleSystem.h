#ifndef EFFECTS_ENGINE_PARTICLE_SYSTEM
#define EFFECTS_ENGINE_PARTICLE_SYSTEM

#include "Particle.h"
#include "Texture/Texture.h"
#include <string>
#include <memory>

namespace effectsEngine
{
	/**
	 * Class that handles a particle system.
	 */
	class ParticleSystem
	{
	public:
		ParticleSystem(glm::vec3&& aWorldPos, std::string&& aTexturePath);

		virtual ~ParticleSystem();

		virtual void Update(float aDeltaTime);

		virtual void Render();

	protected:
		sParticle	mParticles[100U];	//TODO change this to a custom pool
		//TODO blend mode
		glm::vec3	mWorldPos; //TODO change this for scene node
		std::shared_ptr<Texture>	mTexture;		///< Texture the particles will use.
	};
}
#endif
