#include "Bullet.h"

Bullet::Bullet(int startX, int startY, int deltaX, int deltaY)
    : x(startX), y(startY), dx(deltaX), dy(deltaY) {}

void Bullet::update()
{
  x += dx;
  y += dy;
}

void Bullet::render(SDL_Renderer *renderer)
{
  SDL_Rect rect = {x, y, width, height};
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // 흰색 총알
  SDL_RenderFillRect(renderer, &rect);
}

bool Bullet::isOffScreen() const
{
  return (x < 0 || x > 800 || y < 0 || y > 600); // 화면 경계 확인
}