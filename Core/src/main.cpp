#include "EffectsEngine.h"
#include "WindowModule.h"

#include <memory>

int main(int argc, char** argv)
{
    effectsEngine::EffectsEngine Engine;
    effectsEngine::WindowModule Window;
    Engine.AddModule(&Window);

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