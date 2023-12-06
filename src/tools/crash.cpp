#include <ErrorType.hpp>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <tools/crash.hpp>

void crash(std::string msg, ErrorType errorType) {
  std::cerr << msg << std::endl;

  switch (errorType) {
  case ErrorType::SDL:
    std::cerr << "SDL_Error: " << SDL_GetError() << std::endl;
    break;

  case ErrorType::IMG:
    std::cerr << "IMG_Error: " << IMG_GetError() << std::endl;
    break;

  case ErrorType::CUSTOM:
    break;
  }

  exit(EXIT_FAILURE);
}
