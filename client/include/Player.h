#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include <stdbool.h>
#include <cmath>

// 캐릭터 구조체
typedef struct
{
  float x, y;   // 캐릭터의 좌표
  float vx, vy; // 캐릭터의 속도
} Character;

// 입력 처리 함수
void characterHandleInput(
    bool *running,          // 실행 여부
    Character *character,   // 캐릭터
    const int screenWidth,  // 창의 너비
    const int screenHeight, // 창의 높이
    float deltaTime         // 경과 시간 (초)
);

// 캐릭터 렌더링 함수
void renderCharacter(SDL_Renderer *renderer, Character *character);

#endif // PLAYER_H
