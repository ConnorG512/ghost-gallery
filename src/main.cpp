#include <algorithm>
#include <array>
#include <iostream>
#include <memory>
#include <raylib.h>

#include "window.h"
#include "player.h"

int main (int argc, char *argv[]) {

  // std::unique_ptr<Window> game_window{ new Window(1600, 900, 60) };
  Window game_window { 1600, 900, 60 };
  Player player_instance { 6 };

  std::array<Texture2D, 3> loaded_textures = 
  {
    LoadTexture("assets/image/default-background.png"),
    LoadTexture("assets/image/ui/cursor-target.png"),
    LoadTexture("assets/image/entity/enemy/default/default.png"),
  };

  constexpr int enemy_pos_x = 1600 / 2;
  constexpr int enemy_pos_y = 900 / 2;

  HideCursor();

  while (!game_window.shouldWindowClose()) {

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) 
    {
      player_instance.calculateScore( 10 );
    }
    game_window.beginDraw();
    game_window.clearWindow();
    
    DrawTexture(loaded_textures[0], 0, 0, WHITE);
    DrawTexture(loaded_textures[2], enemy_pos_x, enemy_pos_y, WHITE);
    DrawTexture(loaded_textures[1], GetMouseX() - 64, GetMouseY() - 64, WHITE);
    DrawText("Score: ", 10, 10, 32, WHITE);
    DrawText("0", 125, 10, 32, WHITE);

    game_window.endDraw();
  }

  // Unload Texture
  for ( auto texture : loaded_textures )
  {
    UnloadTexture( texture );
  }
  return 0;
}
