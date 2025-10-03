#include "game-manager.h"
#include <raylib.h>
#include <string>

void GameManager::initialiseApplication()
{
  game_window.changeCursorStatus(Window::CursorStatus::hide);
}
void GameManager::drawUpdatePerTick()
{
  game_window.beginDraw();
  game_window.clearWindow();

  background_sprite.drawSprite();
  enemy_sprite.drawSprite();
  cursor_sprite.drawSprite( GetMouseX() - 64, GetMouseY() - 64 );

  DrawText("Score: ", 10, 10, 32, WHITE);
  DrawText(std::to_string(player_instance.m_current_score).c_str(), 125, 10, 32, WHITE);

  game_window.endDraw();
}
void GameManager::inputUpdatePerTick()
{
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) 
    {
      player_instance.addToScore( 10 );
    }
}
bool GameManager::shouldGameClose()
{
  return game_window.shouldWindowClose();
}
