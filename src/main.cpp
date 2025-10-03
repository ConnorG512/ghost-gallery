#include <algorithm>
#include <array>
#include <exception>
#include <iostream>
#include <memory>
#include <raylib.h>

#include "window.h"
#include "player.h"
#include "image-sprite.h"

int main (int argc, char *argv[]) 
{
  // std::unique_ptr<Window> game_window{ new Window(1600, 900, 60) };
  Window game_window { 1600, 900, 60 };
  Player player_instance { 6 };

  constexpr int enemy_pos_x = 1600 / 2 - 64;
  constexpr int enemy_pos_y = 900 / 2 - 64;
  
  ImageSprite background_sprite { "assets/image/default-background.png", 0, 0 };
  ImageSprite cursor_sprite { "assets/image/ui/cursor-target.png", 0, 0 };
  ImageSprite enemy_sprite { "assets/image/entity/enemy/default/default.png", enemy_pos_x, enemy_pos_y };

  HideCursor();

  while (!game_window.shouldWindowClose()) 
  {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) 
    {
      player_instance.calculateScore( 10 );
    }
    game_window.beginDraw();
    game_window.clearWindow();
    
    background_sprite.drawSprite();
    enemy_sprite.drawSprite();
    cursor_sprite.drawSprite(GetMouseX() - 64, GetMouseY() - 64 );

    DrawText("Score: ", 10, 10, 32, WHITE);
    DrawText("0", 125, 10, 32, WHITE);

    game_window.endDraw();
  }

  return 0;
}
