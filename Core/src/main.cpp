#include "EffectsEngine.h"
#include "WindowModule.h"
#include "RenderModule.h"
#include "CameraModule.h"

int main(int argc, char** argv)
{
    effectsEngine::EffectsEngine Engine;
    
    effectsEngine::WindowModule Window;
    Engine.AddModule(&Window);
    
    effectsEngine::RenderModule Render;
    Engine.AddModule(&Render);
    
    effectsEngine::CameraModule Camera;
    Engine.AddModule(&Camera);


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