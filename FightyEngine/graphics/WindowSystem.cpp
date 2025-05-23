#include "WindowSystem.h"

WindowSystem::WindowSystem() : title(std::string()), window(nullptr)
{
    const std::string year = Util::GetCurrentTime("%Y");
    const std::string windowTitle = "Fighty 3D FPS © (" + year + ") by NEWSKINNER. ALL RIGHTS RESERVED";
    SetTitle(windowTitle);
}

WindowSystem::~WindowSystem()
{
    if (window)
        glfwDestroyWindow(window);
    glfwTerminate();
}

bool WindowSystem::Init()
{
    if (!ConfigManager::LoadConfig())
    {
        Util::LogError("Failed to load config file. Check its availability");
        return false;
    }
    /////////////
    isFullScreen = ConfigManager::GetBool("Display", "full_screen_mode");
    isVsyncOn = ConfigManager::GetBool("Display", "vsync");
    /////////////

    if (!glfwInit())
    {
        Util::LogError("GLFW Init error");
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    if (isFullScreen)
        Util::Log("Entered full screen mode");
    else
        Util::Log("Entered windowed mode");
    window = glfwCreateWindow(800, 600, title.c_str(), isFullScreen ? glfwGetPrimaryMonitor() : nullptr, nullptr);
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

void WindowSystem::SetFullScreen(bool active)
{
    isFullScreen = active;
    ConfigManager::SetValue("Display", "full_screen_mode", active ? "true" : "false");
}

void WindowSystem::SetVsync(bool active)
{
    isVsyncOn = active;
    ConfigManager::SetValue("Display", "vsync", active ? "true" : "false");
}