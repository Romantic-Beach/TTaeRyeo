#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <vector>
#include "Player.h"
#include "Bullet.h"

class Game
{
public:
  Game();
  bool init();
  void run();
  void clean();

private:
  SDL_Window *window = nullptr;
  SDL_Renderer *renderer = nullptr;
  bool isRunning = true;
  Player player1;
  Player player2;
  std::vector<Bullet> bullets; // 🔥 총알 목록 추가

  void handleEvents();
  void update();
  void render();
};

#endif