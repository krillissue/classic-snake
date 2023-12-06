#ifndef WINDOW_HPP
#define WINDOW_HPP
#include <SDL2/SDL.h>
#include <Sprite.hpp>
#include <string>
#include <vector>

class Window {
public:
  Window(std::string title, int w, int h, bool accelerated, bool vsync);
  ~Window();

  void clean_up();

  void load_sprite(std::string sprite_path, std::string sprite_name);
  void render_sprite(std::string sprite_name, int x, int y);

  void display_render();
  void clear_render();

private:
  SDL_Window *pr_window;
  SDL_Renderer *pr_renderer;

  std::vector<Sprite> pr_sprites;
};
#endif
