#include "Player.h"

// 캐릭터의 크기
const int CHARACTER_WIDTH = 50;
const int CHARACTER_HEIGHT = 50;

// 캐릭터의 최대 속도, 가속도, 마찰력
const float MAX_SPEED = 200.0f;    // 최대 속도 (픽셀/초)
const float ACCELERATION = 800.0f; // 가속도 (픽셀/초^2)
const float FRICTION = 500.0f;     // 마찰력 (픽셀/초^2)

// 입력 처리 함수
void characterHandleInput(
    bool *running,          // 실행 여부
    Character *character,   // 캐릭터
    const int screenWidth,  // 창의 너비
    const int screenHeight, // 창의 높이
    float deltaTime         // 경과 시간 (초)
)
{
  SDL_Event e;

  // 이벤트 타입이 SDL_QUIT일 경우 running을 false로 설정
  while (SDL_PollEvent(&e) != 0)
  {
    if (e.type == SDL_QUIT)
    {
      *running = false;
    }
  }

  // 키보드 입력 상태 가져오기
  const Uint8 *state = SDL_GetKeyboardState(NULL);

  // 키보드 입력 처리
  if (state[SDL_SCANCODE_UP])
    character->vy -= ACCELERATION * deltaTime;
  if (state[SDL_SCANCODE_DOWN])
    character->vy += ACCELERATION * deltaTime;
  if (state[SDL_SCANCODE_LEFT])
    character->vx -= ACCELERATION * deltaTime;
  if (state[SDL_SCANCODE_RIGHT])
    character->vx += ACCELERATION * deltaTime;

  // 좌우 방향 키가 눌리지 않았을 때 마찰력 적용
  if (!state[SDL_SCANCODE_LEFT] && !state[SDL_SCANCODE_RIGHT])
  {
    if (character->vx > 0)
      character->vx -= FRICTION * deltaTime;
    else if (character->vx < 0)
      character->vx += FRICTION * deltaTime;

    if (fabs(character->vx) < 1.0f)
      character->vx = 0;
  }

  // 상하 방향 키가 눌리지 않았을 때 마찰력 적용
  if (!state[SDL_SCANCODE_UP] && !state[SDL_SCANCODE_DOWN])
  {
    if (character->vy > 0)
      character->vy -= FRICTION * deltaTime;
    else if (character->vy < 0)
      character->vy += FRICTION * deltaTime;

    if (fabs(character->vy) < 1.0f)
      character->vy = 0;
  }

  // 캐릭터 위치 업데이트
  character->x += character->vx * deltaTime;
  character->y += character->vy * deltaTime;

  // 캐릭터가 창의 경계를 벗어나지 않도록 제한
  if (character->x < 0)
    character->x = 0;
  if (character->y < 0)
    character->y = 0;
  if (character->x + CHARACTER_WIDTH > screenWidth)
    character->x = screenWidth - CHARACTER_WIDTH;
  if (character->y + CHARACTER_HEIGHT > screenHeight)
    character->y = screenHeight - CHARACTER_HEIGHT;
}

// 캐릭터 렌더링 함수
void renderCharacter(SDL_Renderer *renderer, Character *character)
{
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
  SDL_Rect fillRect = {(int)character->x, (int)character->y, CHARACTER_WIDTH, CHARACTER_HEIGHT};
  SDL_RenderFillRect(renderer, &fillRect);
}