#ifndef GAME_HPP
#define GAME_HPP
#include <Window.hpp>

class Game {
public:
  Game(Window *window);
  ~Game();

  void clean_up();

  void mainloop();

private:
  Window *pr_window;
};

#endif