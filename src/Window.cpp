#include <ErrorType.hpp>
#include <SDL2/SDL.h>
#include <Sprite.hpp>
#include <Window.hpp>
#include <string>
#include <tools/crash.hpp>

Window::Window(std::string arg_title, int arg_w, int arg_h, bool accelerated,
               bool vsync)
    : pr_window(NULL), pr_renderer(NULL) {
  pr_window =
      SDL_CreateWindow(arg_title.c_str(), SDL_WINDOWPOS_UNDEFINED,
                       SDL_WINDOWPOS_UNDEFINED, arg_w, arg_h, SDL_WINDOW_SHOWN);

  if (!pr_window)
    crash("SDL_CreateWindow failed.", ErrorType::SDL);

  int renderer_flags = 0;

  if (accelerated)
    renderer_flags = renderer_flags | SDL_RENDERER_ACCELERATED;
  if (vsync)
    renderer_flags = renderer_flags | SDL_RENDERER_PRESENTVSYNC;

  pr_renderer = SDL_CreateRenderer(pr_window, -1, renderer_flags);
}

Window::~Window() { clean_up(); }

void Window::mainloop() {
  SDL_Event event;

  while (true) {
    SDL_PollEvent(&event);

    if (event.type == SDL_QUIT)
      break;
  }
}

void Window::clean_up() {
  SDL_DestroyRenderer(pr_renderer);
  SDL_DestroyWindow(pr_window);
}

void Window::load_sprite(std::string sprite_path, std::string sprite_name) {
  SDL_Texture *texture = NULL;
  texture = IMG_LoadTexture(pr_renderer, sprite_path.c_str());

  if (!texture)
    crash("IMG_LoadTexture failed.", ErrorType::IMG);

  pr_sprites.push_back({.texture = texture, .name = sprite_name});
}
