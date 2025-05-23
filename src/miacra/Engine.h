#pragma once

#include <string>
#include "../graphics/WindowSystem.h"
#include "../graphics/Renderer.h"
#include "../graphics/TextRenderer.h"

class WindowSystem;
class Renderer;

class Engine
{
public:
  Engine(const std::string &gameTitle = "Fighty");
  ~Engine();

  bool Init();
  void Run();
  void Shutdown();

private:
  void ProcessInput();
  void Update(float deltaTime);
  void Render();
  void CalculateDeltaTime();

  bool isRunning;
  float lastFrameTime;
  std::string title;

  WindowSystem *windowSystem;
  Renderer *renderer;
  // TextRenderer *textRenderer;
};