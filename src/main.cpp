#include <memory>
#include <raylib.h>

#include "window.h"

int main (int argc, char *argv[]) {

  // std::unique_ptr<Window> game_window{ new Window(1600, 900, 60) };
  Window game_window { 1600, 900, 60 };

  // Load background image
  Texture2D background_sprite = LoadTexture("assets/image/default-background.png");
  Texture2D cursor = LoadTexture("assets/image/ui/cursor-target.png");

  while (!game_window.shouldWindowClose()) {
    game_window.beginDraw();
    game_window.clearWindow();
    DrawTexture(background_sprite, 0, 0, WHITE);
    DrawTexture(cursor, GetMouseX(), GetMouseY(), WHITE);
    game_window.endDraw();
  }

  // Unload Texture
  UnloadTexture(background_sprite);
  UnloadTexture(cursor);

  return 0;
}
