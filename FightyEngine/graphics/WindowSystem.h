#pragma once

#include <string>
#include <GLFW/glfw3.h>

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

private:
    std::string title;
    GLFWwindow *window;
};