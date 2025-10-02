#include "window.h"
#include <memory>

int main (int argc, char *argv[]) {
  
  // std::unique_ptr<Window> game_window{ new Window(1600, 900, 60) };
  Window game_window { 1600, 900, 60 };

  while (!game_window.shouldWindowClose()) {
    game_window.beginDraw();
    game_window.clearWindow();
    game_window.endDraw();
  }
  
  return 0;
}
