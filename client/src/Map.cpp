#include "Map.h"

void setBackground(SDL_Renderer *renderer, int r, int g, int b)
{
  SDL_SetRenderDrawColor(renderer, r, g, b, 255);
  SDL_RenderClear(renderer);
}