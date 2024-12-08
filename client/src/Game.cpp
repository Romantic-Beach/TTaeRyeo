#include "Game.h"

Game::Game()
    : player1(100, 100, 1),
      player2(600, 400, 2)
{
}

bool Game::init()
{
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) != 0)
  {
    SDL_Log("SDL Initialization failed: %s", SDL_GetError());
    return false;
  }

  window = SDL_CreateWindow("1대1 조이스틱 탑다운 슈팅 게임", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  return true;
}

void Game::run()
{
  while (isRunning)
  {
    handleEvents();
    update();
    render();
    SDL_Delay(16); // 60 FPS
  }
}

void Game::handleEvents()
{
  SDL_Event event;
  while (SDL_PollEvent(&event))
  {
    if (event.type == SDL_QUIT)
    {
      isRunning = false;
    }
    player1.handleInput(event, bullets);
    player2.handleInput(event, bullets);
  }
}

void Game::update()
{
  player1.update();
  player2.update();
  for (auto &bullet : bullets)
  {
    bullet.update();
  }
  bullets.erase(std::remove_if(bullets.begin(), bullets.end(),
                               [](Bullet &b)
                               { return b.isOffScreen(); }),
                bullets.end());
}

void Game::render()
{
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);
  player1.render(renderer);
  player2.render(renderer);
  for (auto &bullet : bullets)
  {
    bullet.render(renderer);
  }
  SDL_RenderPresent(renderer);
}

void Game::clean()
{
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}