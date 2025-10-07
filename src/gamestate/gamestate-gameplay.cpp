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

  m_game_tick.incrementTick();
  resetEnemyOnTick();
}

void GameStateGameplay::gameplayLoop()
{
  m_game_window.beginDraw();
  m_game_window.clearWindow();

  m_background_image.drawSprite( 0 );
  m_enemy_sprite.drawToScreen( 0 );

  cursorHoverOverEnemy();

  TextRender::drawTextToScreen( 
    std::format("{} {}", "Score:", std::to_string(m_player.current_score)), 
    score_text_offset, 
    score_text_offset, 
    font_size 
  ); 

  m_game_window.endDraw();
}

void GameStateGameplay::cursorHoverOverEnemy()
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

void GameStateGameplay::respawnEnemy()
{
  m_enemy_sprite.drawToScreen(
    0,
    RandomGeneration::generateRandomNumberBetween(0, 1600),
    RandomGeneration::generateRandomNumberBetween(0, 900)
  );
  m_enemy_sprite.reviveEntity();
}

void GameStateGameplay::playerShoot()
{
  if ( InputHandler::leftMousePressed() && m_player.checkCollision( m_enemy_sprite.getCollision()))
  {
    if (m_enemy_sprite.takeDamage(m_player.fire_damage) <= 0 )
    {
      m_game_tick.resetTickCounter();
      respawnEnemy();
      m_player.addToScore( score_amount_to_add );
    }
  }
}

void GameStateGameplay::resetEnemyOnTick()
{
  if ( m_game_tick.hasHitTick( 120 ))
  {
    respawnEnemy();
  }
}
