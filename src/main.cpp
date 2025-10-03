#include <memory>
#include <raylib.h>

#include "window.h"

int main (int argc, char *argv[]) {

  // std::unique_ptr<Window> game_window{ new Window(1600, 900, 60) };
  Window game_window { 1600, 900, 60 };

  // Load background image
  Texture2D background_sprite = LoadTexture("assets/image/default-background.png");
  Texture2D cursor = LoadTexture("assets/image/ui/cursor-target.png");
  Texture2D enemy_default = LoadTexture("assets/image/entity/enemy/default/default.png");

  // Player stats
  int current_player_lives { 6 };
  constexpr int max_player_lives { 6 };
  int current_player_score { 0 };
  constexpr int max_player_score { 100000 };

  constexpr int enemy_pos_x = 1600 / 2;
  constexpr int enemy_pos_y = 900 / 2;

  while (!game_window.shouldWindowClose()) {
    game_window.beginDraw();
    game_window.clearWindow();
    
    DrawTexture(background_sprite, 0, 0, WHITE);
    DrawTexture(enemy_default, 1600 / 2, 900 / 2, WHITE);
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
