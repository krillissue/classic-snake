#ifndef SPRITE_HPP
#define SPRITE_HPP
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

struct Sprite {
  SDL_Texture *texture;
  std::string name;
};
#endif
