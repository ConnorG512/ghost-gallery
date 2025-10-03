#include "game-manager.h"

int main (int argc, char *argv[]) 
{
  // std::unique_ptr<Window> game_window{ new Window(1600, 900, 60) };
  GameManager game_manager { };
  
  game_manager.initialiseApplication();
  
  while (!game_manager.shouldGameClose()) {
    game_manager.inputUpdatePerTick();
    game_manager.drawUpdatePerTick();
  }

  return 0;
}
