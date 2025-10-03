#include <iostream>
#include <memory>
#include <raylib.h>

#include "window.h"
#include "player.h"

int main (int argc, char *argv[]) {

  // std::unique_ptr<Window> game_window{ new Window(1600, 900, 60) };
  Window game_window { 1600, 900, 60 };
  Player player_instance { 6 };

  // Load background image
  Texture2D background_sprite = LoadTexture("assets/image/default-background.png");
  Texture2D cursor = LoadTexture("assets/image/ui/cursor-target.png");
  Texture2D enemy_default = LoadTexture("assets/image/entity/enemy/default/default.png");

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
    
    DrawTexture(background_sprite, 0, 0, WHITE);
    DrawTexture(enemy_default, enemy_pos_x, enemy_pos_y, WHITE);
    DrawTexture(cursor, GetMouseX() - 64, GetMouseY() - 64, WHITE);
    DrawText("Score: ", 10, 10, 32, WHITE);
    DrawText("0", 125, 10, 32, WHITE);

    game_window.endDraw();
  }

  // Unload Texture
  UnloadTexture(background_sprite);
  UnloadTexture(cursor);
  UnloadTexture(enemy_default);

  return 0;
}
