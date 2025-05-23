#include "Engine.h"
#include "Util.h"

Engine::Engine()
    : isRunning(false), lastFrameTime(0.0f), windowSystem(nullptr), renderer(nullptr) {}

Engine::~Engine() { Shutdown(); }

bool Engine::Init()
{
  Util::Log("Engine::Init() started");

  windowSystem = new WindowSystem();
  if (!windowSystem->Init())
  {
    Util::LogError("WindowSystem::Init() failed");
    return false;
  }

  renderer = new Renderer();
  if (!renderer->Init())
  {
    Util::LogError("Renderer::Init() failed");
    return false;
  }

  // @TODO: Realize the TextRenderer::TextRenderer()
  isRunning = true;
  return true;
}

void Engine::Run()
{
  while (isRunning && !windowSystem->ShouldClose())
  {
    CalculateDeltaTime();
    ProcessInput();
    Update(lastFrameTime);
    Render();

    windowSystem->SwapBuffers();
    windowSystem->PollEvents();
  }
}

void Engine::Shutdown()
{
  Util::Log("Quitting...");
  delete renderer;
  delete windowSystem;
}

void Engine::CalculateDeltaTime()
{
  static auto previous = std::chrono::high_resolution_clock::now();
  auto current = std::chrono::high_resolution_clock::now();
  std::chrono::duration<float> delta = current - previous;
  lastFrameTime = delta.count();
  previous = current;
}

void Engine::ProcessInput()
{
  if (windowSystem->IsKeyPressed(GLFW_KEY_ESCAPE))
    isRunning = false;
}

void Engine::Update(float deltaTime)
{
}

void Engine::Render()
{
  renderer->Clear();
}
