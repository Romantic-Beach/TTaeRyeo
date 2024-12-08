#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include <vector>
#include "Bullet.h"

class Player
{
public:
  Player();
  Player(int x, int y, int id);
  void handleInput(const SDL_Event &event, std::vector<Bullet> &bullets);
  void update();
  void render(SDL_Renderer *renderer);
  void shoot(std::vector<Bullet> &bullets); // 🔥 shoot 메서드에 bullets 전달

private:
  int x, y;                    // 플레이어의 위치
  int width = 50, height = 50; // 플레이어의 크기
  int playerId;                // 1P 또는 2P를 나타냄
  int health = 3;              // 플레이어의 체력

  // 🔥 속도 추가 (velocity)
  int velocityX = 0;      // x축 속도
  int velocityY = 0;      // y축 속도
  const int maxSpeed = 5; // 플레이어의 최대 속도

  // 🔥 총알 발사 쿨타임 관리
  Uint32 lastShotTime = 0;      // 마지막 발사 시간 (ms)
  const Uint32 fireRate = 1000; // 발사 간격 (1000ms = 1초)
};

#endif