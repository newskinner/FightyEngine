#pragma once

#define GL_GLEXT_PROTOTYPES
#include "../miacra/Util.h"
#include <GL/gl.h>
#include <GLFW/glfw3.h>

class Renderer
{
public:
    bool Init();
    void Clear();
    void Render();
    void Shutdown();
};