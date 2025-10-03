#include "game-manager.h"
#include <raylib.h>

void GameManager::initialiseApplication()
{
  HideCursor();
}
void GameManager::drawUpdatePerTick()
{
  game_window.beginDraw();
  game_window.clearWindow();

  background_sprite.drawSprite();
  enemy_sprite.drawSprite();
  cursor_sprite.drawSprite( GetMouseX() - 64, GetMouseY() - 64 );

  DrawText("Score: ", 10, 10, 32, WHITE);
  DrawText("0", 125, 10, 32, WHITE);

  game_window.endDraw();
}
void GameManager::inputUpdatePerTick()
{
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) 
    {
      player_instance.calculateScore( 10 );
    }
}
bool GameManager::shouldGameClose()
{
  return game_window.shouldWindowClose();
}
