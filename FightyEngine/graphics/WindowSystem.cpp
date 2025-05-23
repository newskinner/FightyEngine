#include "WindowSystem.h"
#include "../miacra/Util.h"

WindowSystem::WindowSystem(const std::string &title) : title(title), window(nullptr) {}

WindowSystem::~WindowSystem()
{
    if (window)
        glfwDestroyWindow(window);
    glfwTerminate();
}

bool WindowSystem::Init()
{
    if (!glfwInit())
    {
        Util::LogError("GLFW Init error");
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(800, 600, title.c_str(), nullptr, nullptr);
    if (!window)
    {
        Util::LogError("Failed to create GLFW window");
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(window);
    return true;
}

void WindowSystem::SwapBuffers()
{
    glfwSwapBuffers(window);
}

void WindowSystem::PollEvents()
{
    glfwPollEvents();
}

bool WindowSystem::ShouldClose() const
{
    return glfwWindowShouldClose(window);
}

bool WindowSystem::IsKeyPressed(int key) const
{
    return glfwGetKey(window, key) == GLFW_PRESS;
}

void WindowSystem::SetTitle(const std::string &newTitle)
{
    title = newTitle;
    if (window)
        glfwSetWindowTitle(window, title.c_str());
}