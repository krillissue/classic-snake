#ifndef WINDOW_HPP
#define WINDOW_HPP
#include <SDL2/SDL.h>
#include <Sprite.hpp>
#include <string>
#include <vector>

class Window {
public:
  Window(std::string arg_title, int arg_w, int arg_h, bool accelerated,
         bool vsync);
  ~Window();

  void mainloop();
  void clean_up();

  void load_sprite(std::string sprite_path, std::string sprite_name);

private:
  SDL_Window *pr_window;
  SDL_Renderer *pr_renderer;

  std::vector<Sprite> pr_sprites;
};
#endif
