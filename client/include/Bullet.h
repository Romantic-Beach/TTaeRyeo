#ifndef BULLET_H
#define BULLET_H

#include <SDL2/SDL.h>

class Bullet {
public:
    Bullet(int x, int y, int dx, int dy);
    void update();
    void render(SDL_Renderer* renderer);
    bool isOffScreen() const;

private:
    int x, y;
    int dx, dy; // 총알의 속도 (dx, dy)
    int width = 10, height = 10; // 총알 크기
};

#endif