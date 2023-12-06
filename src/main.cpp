#include <iostream>
#include <SDL2/SDL.h>
#include <tools/crash.hpp>
#include <Window.hpp>

int main(void) {
  if (SDL_Init(SDL_INIT_VIDEO) != EXIT_SUCCESS)
    crash("SDL_Init failed.");

  Window window("Classic Snake", 640, 480, true, true);
  SDL_Event event;

  while (true) {
    SDL_PollEvent(&event);

    if (event.type == SDL_QUIT)
      break;
  }

  window.clean_up();
  SDL_Quit();

  return EXIT_SUCCESS;
}
