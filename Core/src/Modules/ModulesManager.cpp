#include "ModulesManager.h"
#include "CameraModule.h"
#include "WindowModule.h"
#include "RenderModule.h"

namespace effectsEngine
{

	ModulesManager::tModules ModulesManager::mModules = ModulesManager::tModules();

	ModulesManager::ModulesManager() 	
	{
	}

	ModulesManager::~ModulesManager()
	{
	}

	void ModulesManager::AddModule(eModule aModule)
	{
		IModule* newModule;
		switch (aModule)
		{
			case eModule::Camera:
			{
				newModule = new CameraModule();
				break;
			}
			case eModule::Render:
			{
				newModule = new RenderModule();
				break;
			}
			case eModule::Window:
			{
				newModule = new WindowModule();
				break;
			}
		}
		mModules.emplace(aModule, std::unique_ptr<IModule>(newModule));
	}

	const ModulesManager::tModules& ModulesManager::GetModules() const
	{
		return mModules;
	}
}