#pragma once

#include <string>
#include <GLFW/glfw3.h>
#include "../miacra/Engine.h"
#include "../miacra/ConfigManager.h"

class WindowSystem
{
public:
    WindowSystem();
    ~WindowSystem();

    bool Init();
    void SwapBuffers();
    void PollEvents();
    bool ShouldClose() const;
    bool IsKeyPressed(int key) const;
    void SetTitle(const std::string &newTitle);

    bool isFullScreen;

private:
    std::string title;
    GLFWwindow *window;
};