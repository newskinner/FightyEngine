#include "miacra/Engine.h"
#include "miacra/Util.h"

int main(void)
{
    Engine engine;
    if (!engine.Init())
        return Util::LogError("Engine initialization failed");
    engine.Run();
    return 0;
}