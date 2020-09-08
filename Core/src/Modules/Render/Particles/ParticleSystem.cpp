#include "ParticleSystem.h"
#include "Texture/TexturesManager.h"

namespace effectsEngine
{
	ParticleSystem::ParticleSystem(glm::vec3&& aWorldPos, std::string&& aTexturePath) :
		mWorldPos(aWorldPos)
	{
		mTexture = TexturesManager::GetInstance().GetResource(aTexturePath);
	}

	ParticleSystem::~ParticleSystem()
	{
	}

	void ParticleSystem::Update(float aDeltaTime)
	{
	}

	void ParticleSystem::Render()
	{
	}
}