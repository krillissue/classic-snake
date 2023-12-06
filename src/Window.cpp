#include <string>
#include <SDL2/SDL.h>
#include <Window.hpp>
#include <tools/crash.hpp>

Window::Window(const std::string arg_title, int arg_w, int arg_h, bool accelerated, bool vsync) : pr_window(NULL), pr_renderer(NULL) {
  pr_window = SDL_CreateWindow(arg_title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, arg_w, arg_h, SDL_WINDOW_SHOWN);

  if (!pr_window)
    crash("SDL_CreateWindow failed.");

  int renderer_flags = 0;

  if (accelerated) renderer_flags = renderer_flags | SDL_RENDERER_ACCELERATED;
  if (vsync) renderer_flags = renderer_flags | SDL_RENDERER_PRESENTVSYNC;

  pr_renderer = SDL_CreateRenderer(pr_window, -1, renderer_flags);
}

Window::~Window() {
  clean_up();
}

void Window::clean_up() {
  SDL_DestroyRenderer(pr_renderer);
  SDL_DestroyWindow(pr_window);
}
