#include "game-manager.h"

#include <format>
#include <iostream>
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
  enemy_sprite.drawToScreen();
  player_instance.drawToScreen( GetMouseX() - 64, GetMouseY() - 64 );

  if (player_instance.checkCollision(enemy_sprite.getCollision()))
  {
    std::cout << "Hit!" << std::endl;
    std::cout << std::to_string(player_instance.getCollision().x) << std::to_string(player_instance.getCollision().y) << std::endl;
  }

  TextRender::drawTextToScreen( std::format("{}: {}", "Score", std::to_string(player_instance.m_current_score)), 10, 10, 32 );

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
