#include "EffectsEngine.h"
#include "IModule.h"

namespace effectsEngine
{
	EffectsEngine::EffectsEngine() : 
		mModules()
	{

	}

	EffectsEngine::~EffectsEngine()
	{

	}

	void EffectsEngine::AddModule(IModule* aModule)
	{
		mModules.push_back(aModule);
	}

	bool EffectsEngine::Init()
	{
		for (IModule* currentModule : mModules)
		{
			if (!currentModule->Init())
			{
				return false;
			}
		}
	}

	bool EffectsEngine::Update(float aDeltaTime)
	{
		for (IModule* currentModule : mModules)
		{
			if (!currentModule->Update(aDeltaTime))
			{
				return false;
			}
		}
	}

	void EffectsEngine::Clean()
	{
		for (IModule* currentModule : mModules)
		{
			currentModule->Clean();
		}
	}
}