#include "Renderer.h"

static unsigned int vao = 0, vbo = 0;

bool Renderer::Init()
{
    Util::Log("Renderer Init started");
    int width, height;
    glfwGetFramebufferSize(glfwGetCurrentContext(), &width, &height);
    glViewport(0, 0, width, height);

    const GLubyte *renderer = glGetString(GL_RENDERER);
    const GLubyte *ver = glGetString(GL_VERSION);
    if (!renderer || !ver)
    {
        Util::LogError("Failed to retrieve OpenGL context info");
        return false;
    }

    Util::Log("OpenGL Renderer: " + std::string(reinterpret_cast<const char *>(renderer)));
    Util::Log("OpenGL Version: " + std::string(reinterpret_cast<const char *>(ver)));

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    return true;
}

void Renderer::Clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::Render()
{
}

void Renderer::Shutdown()
{
}
