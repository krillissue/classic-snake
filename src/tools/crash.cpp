#include <iostream>
#include <SDL2/SDL.h>
#include <tools/crash.hpp>

void crash(std::string msg) {
  std::cerr << msg << std::endl;
  std::cerr << "SDL_Error: " << SDL_GetError() << std::endl;

  exit(EXIT_FAILURE);
}
