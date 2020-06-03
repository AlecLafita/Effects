#include "EffectsEngine.h"
#include "ModulesCommon.h"

int main(int argc, char** argv)
{
    effectsEngine::EffectsEngine Engine;
    
    Engine.AddModule(effectsEngine::eModule::Camera);
    Engine.AddModule(effectsEngine::eModule::Render);
    Engine.AddModule(effectsEngine::eModule::Window);

    if (Engine.Init())
    {
        bool exit = false;
        while (!exit)
        {
            exit = !Engine.Update(0.0f); //TODO delta time
        }

        Engine.Clean();
    }
 
    return 0;
}