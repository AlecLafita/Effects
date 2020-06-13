#include "EffectsEngine.h"
#include "IModule.h"
#include "ServiceLocator.h"
#include "ModelLoaderAssimp.h"

namespace effectsEngine
{
	EffectsEngine::EffectsEngine() : 
		mModulesManager()
	{

	}

	EffectsEngine::~EffectsEngine()
	{

	}

	void EffectsEngine::AddModule(eModule aModule)
	{
		mModulesManager.AddModule(aModule);
	}

	bool EffectsEngine::Init()
	{
		ServiceLocator<IModelLoader>::ProvideService(new ModelLoaderAssimp());

		for (const auto& currentModuleIterator : mModulesManager.GetModules())
		{
			if (!currentModuleIterator.second->Init())
			{
				return false;
			}
		}
		
		return true;
	}

	bool EffectsEngine::Update(float aDeltaTime)
	{
		for (const auto& currentModuleIterator : mModulesManager.GetModules())
		{
			if (!currentModuleIterator.second->Update(aDeltaTime))
			{
				return false;
			}
		}
		
		return true;
	}

	void EffectsEngine::Clean()
	{
		for (const auto& currentModuleIterator : mModulesManager.GetModules())
		{
			currentModuleIterator.second->Clean();
		}
	}
}