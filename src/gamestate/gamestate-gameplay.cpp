#include "gamestate-gameplay.h"
#include "gamestate-base.h"
#include "../text-render.h"
#include "../window.h"
#include <format>
#include <string>

GameStateGameplay::GameStateGameplay( Window& game_window )
  : GameState { game_window } {};

namespace 
{
  constexpr int cursor_offset { 64 };
}

void GameStateGameplay::initialiseState()
{
  m_game_window.changeCursorStatus( Window::CursorStatus::hide );
}

void GameStateGameplay::inputLoop()
{
  // TODO
}

void GameStateGameplay::gameplayLoop()
{
  m_game_window.beginDraw();
  m_game_window.clearWindow();

  m_background_image.drawSprite();
  m_enemy_sprite.drawToScreen();
  m_player.drawToScreen( m_game_window.getCursorX() - cursor_offset, m_game_window.getCursorY() - cursor_offset );

  TextRender::drawTextToScreen( std::format("{} {}", "Score:", std::to_string(m_player.m_current_score)), 10, 10, 32 ); 

  m_game_window.endDraw();
}
