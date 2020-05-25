#include "EffectsEngine.h"
#include "WindowModule.h"
#include "RenderModule.h"

#include <memory>

int main(int argc, char** argv)
{
    effectsEngine::EffectsEngine Engine;
    effectsEngine::WindowModule Window;
    effectsEngine::RenderModule Render;
    Engine.AddModule(&Window);
    Engine.AddModule(&Render);

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