#include "Player.h"
#include "Bullet.h"

Player::Player() : x(0), y(0), playerId(0) {}

Player::Player(int startX, int startY, int id) : x(startX), y(startY), playerId(id) {}

void Player::handleInput(const SDL_Event &event, std::vector<Bullet> &bullets)
{
  if (playerId == 1)
  {
    // 조이스틱 조작 코드
  }
  else if (playerId == 2)
  {
    // 키보드 입력 상태 가져오기
    const Uint8 *state = SDL_GetKeyboardState(NULL);

    // 키보드 입력 처리 (속도 적용)
    if (state[SDL_SCANCODE_UP])
      velocityY = -maxSpeed;
    else if (state[SDL_SCANCODE_DOWN])
      velocityY = maxSpeed;
    else
      velocityY = 0;

    if (state[SDL_SCANCODE_LEFT])
      velocityX = -maxSpeed;
    else if (state[SDL_SCANCODE_RIGHT])
      velocityX = maxSpeed;
    else
      velocityX = 0;

    // 스페이스바를 누르면 총알 발사
    if (state[SDL_SCANCODE_SPACE])
      shoot(bullets);
  }
}

void Player::update()
{
  // 🔥 위치 업데이트 로직
  x += velocityX; // x축 속도에 따른 위치 변경
  y += velocityY; // y축 속도에 따른 위치 변경

  // 🔥 화면 경계 충돌 감지 및 위치 제한
  if (x < 0)
    x = 0; // 왼쪽 경계
  if (x + width > 800)
    x = 800 - width; // 오른쪽 경계
  if (y < 0)
    y = 0; // 위쪽 경계
  if (y + height > 600)
    y = 600 - height; // 아래쪽 경계
}

void Player::render(SDL_Renderer *renderer)
{
  SDL_Rect rect = {x, y, width, height};
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // 빨간색 플레이어
  SDL_RenderFillRect(renderer, &rect);
}

void Player::shoot(std::vector<Bullet> &bullets)
{
  Uint32 currentTime = SDL_GetTicks(); // 현재 시간(ms)
  if (currentTime - lastShotTime < fireRate)
  {
    // 🔥 쿨타임이 지나지 않으면 발사하지 않음
    return;
  }

  lastShotTime = currentTime;                 // 마지막 발사 시간 갱신
  Bullet newBullet(x + width / 2, y, 0, -10); // 위로 발사 (x, y, dx, dy)
  bullets.push_back(newBullet);               // 벡터에 총알 추가
}