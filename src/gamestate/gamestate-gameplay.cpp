#include "gamestate-gameplay.h"
#include "gamestate-base.h"
#include "../text-render.h"
#include "../window.h"
#include "../input-handler.h"
#include <format>
#include <iostream>
#include <ostream>
#include <raylib.h>
#include <string>

GameStateGameplay::GameStateGameplay( Window& game_window )
  : GameState { game_window } {};

namespace 
{
  constexpr int cursor_offset { 64 };
  constexpr int score_text_offset { 10 };
  constexpr int score_amount_to_add { 20 };
}

void GameStateGameplay::initialiseState()
{
  m_game_window.changeCursorStatus( Window::CursorStatus::hide );
}

void GameStateGameplay::inputLoop()
{
  playerShoot();
}

void GameStateGameplay::gameplayLoop()
{
  m_game_window.beginDraw();
  m_game_window.clearWindow();

  m_background_image.drawSprite( 0 );
  m_enemy_sprite.drawToScreen( 0 );

  if ( m_player.checkCollision( m_enemy_sprite.getCollision()))
  {
    m_player.drawToScreen( 1, m_game_window.getCursorX() - cursor_offset, m_game_window.getCursorY() - cursor_offset );
  } 
  else 
  {
    m_player.drawToScreen( 0, m_game_window.getCursorX() - cursor_offset, m_game_window.getCursorY() - cursor_offset );
  }

  TextRender::drawTextToScreen( 
    std::format("{} {}", "Score:", 
    std::to_string(m_player.m_current_score)), 
    score_text_offset, 
    score_text_offset, 
    32 
  ); 

  m_game_window.endDraw();
}

void GameStateGameplay::playerShoot()
{
  if ( InputHandler::leftMousePressed())
  {
    if ( m_player.checkCollision( m_enemy_sprite.getCollision()) )
    {
      m_player.addToScore( score_amount_to_add );
    }
  }
}
