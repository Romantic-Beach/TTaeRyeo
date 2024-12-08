#include <SDL2/SDL.h>
#include "Player.h"
#include "Map.h"

// 창의 크기
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

// SDL 초기화 및 창 생성
bool init(SDL_Window **window, SDL_Renderer **renderer)
{
    // SDL 초기화
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL 초기화 실패: %s\n", SDL_GetError());
        return false;
    }

    // 창 생성s
    *window = SDL_CreateWindow("SDL2 캐릭터 움직이기",
                               SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED,
                               SCREEN_WIDTH, SCREEN_HEIGHT,
                               SDL_WINDOW_SHOWN);

    // 창 생성 실패시
    if (*window == NULL)
    {
        printf("창 생성 실패: %s\n", SDL_GetError());
        return false;
    }

    // 렌더러 생성
    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);

    // 렌더러 생성 실패시
    if (*renderer == NULL)
    {
        printf("렌더러 생성 실패: %s\n", SDL_GetError());
        return false;
    }

    return true;
}

// SDL 리소스 정리
void close(SDL_Window *window, SDL_Renderer *renderer)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main()
{
    SDL_Window *window = NULL;                                                     // 창
    SDL_Renderer *renderer = NULL;                                                 // 렌더러
    Uint32 lastTime = SDL_GetTicks();                                              // 마지막 시간
    Character character = {SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f, 0.0f, 0.0f}; // 캐릭터
    bool running = true;                                                           // 실행 여부

    // SDL 초기화 및 창 생성 실패시
    if (!init(&window, &renderer))
    {
        // 프로그램 종료
        return -1;
    }

    // 게임 루프
    while (running)
    {
        // 현재 시간 계산
        Uint32 currentTime = SDL_GetTicks();

        // 경과 시간 계산
        float deltaTime = (currentTime - lastTime) / 1000.0f;

        // 마지막 시간 갱신
        lastTime = currentTime;

        // 캐릭터 키보드 이벤트 처리
        characterHandleInput(
            &running,      // 실행 여부
            &character,    // 캐릭터
            SCREEN_WIDTH,  // 화면 너비
            SCREEN_HEIGHT, // 화면 높이
            deltaTime      // 경과 시간 (초)
        );

        // 배경화면 설정
        setBackground(renderer, 0, 0, 0);

        // 캐릭터 렌더링
        renderCharacter(renderer, &character);

        // 화면 업데이트
        SDL_RenderPresent(renderer);
    }

    // SDL 리소스 정리
    close(window, renderer);

    // 프로그램 종료
    return 0;
}