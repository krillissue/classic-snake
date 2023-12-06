#ifndef WINDOW_HPP
#define WINDOW_HPP
#include <SDL2/SDL.h>
#include <string>

class Window {
public:
  Window(const std::string arg_title, int arg_w, int arg_h, bool accelerated,
         bool vsync);
  ~Window();

  void mainloop();
  void clean_up();

private:
  SDL_Window *pr_window;
  SDL_Renderer *pr_renderer;
};
#endif
