#include "gamestate-gameplay.h"
#include "gamestate-base.h"
#include "../text-render.h"
#include "../window.h"
#include "../input-handler.h"
#include <format>
#include <raylib.h>
#include <string>

GameStateGameplay::GameStateGameplay( Window& game_window )
  : GameState { game_window } {};

namespace 
{
  constexpr int cursor_offset { 64 };
  constexpr int score_text_offset { 10 };
  constexpr int score_amount_to_add { 20 };
  constexpr int font_size { 32 }; 
}

void GameStateGameplay::initialiseState()
{
  m_game_window.changeCursorStatus( Window::CursorStatus::hide );
}

void GameStateGameplay::inputLoop()
{
  playerShoot();
}

void GameStateGameplay::changePlayerCursor()
{
  if ( m_player.checkCollision( m_enemy_sprite.getCollision()))
  {
    m_player.changePlayerCursor(Player::TextureName::targeted, m_game_window );
  } 
  else 
  {
    m_player.changePlayerCursor(Player::TextureName::not_targeted, m_game_window );
  }
}

void GameStateGameplay::gameplayLoop()
{
  m_game_window.beginDraw();
  m_game_window.clearWindow();

  m_background_image.drawSprite( 0 );
  m_enemy_sprite.drawToScreen( 0 );

  changePlayerCursor();

  TextRender::drawTextToScreen( 
    std::format("{} {}", "Score:", std::to_string(m_player.current_score)), 
    score_text_offset, 
    score_text_offset, 
    font_size 
  ); 

  m_game_window.endDraw();
}

void GameStateGameplay::playerShoot()
{
  if ( InputHandler::leftMousePressed() && m_player.checkCollision( m_enemy_sprite.getCollision()))
  {
    if (m_enemy_sprite.takeDamage(m_player.fire_damage) <= 0 )
    {
      m_player.addToScore( score_amount_to_add );
    }
  }
}
