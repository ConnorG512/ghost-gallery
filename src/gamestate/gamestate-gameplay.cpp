#include "gamestate-gameplay.h"
#include "gamestate-base.h"
#include "../text-render.h"
#include "../window.h"
#include "../input-handler.h"
#include "../game-manager.h"
#include <array>
#include <format>
#include <raylib.h>
#include <string>
#include <unistd.h>

GameStateGameplay::GameStateGameplay( GameManager* game_manager, Window& game_window )
  : GameState { game_manager, game_window } {};

namespace 
{
  constexpr int player_dealt_damage { 1 };
  constexpr int score_amount_to_add { 20 };
}

void GameStateGameplay::initialiseState()
{
  m_game_window.changeCursorStatus( Window::CursorStatus::hide );
}

void GameStateGameplay::inputLoop()
{
  startTickEvent();
  playerShoot();
}

void GameStateGameplay::gameplayLoop()
{
  m_game_window.beginDraw();
  m_game_window.clearWindow();

  m_background_image.drawSprite( 0 );
  m_enemy_sprite.drawToScreen( 0 );
  m_heart_collectable.drawToScreen( 0 );

  cursorHoverOverEnemy();

  drawGameUi();

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
  constexpr std::array<int, 2> x_screen_pos_min_max { 200, 1400 };
  constexpr std::array<int, 2> y_screen_pos_min_max { 100, 800 };
  
  m_enemy_sprite.drawToScreen(
    0,
    RandomGeneration::NumberBetween( x_screen_pos_min_max[ 0 ], x_screen_pos_min_max[ 1 ] ),
    RandomGeneration::NumberBetween( y_screen_pos_min_max[ 0 ], y_screen_pos_min_max[ 1 ] )
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
  respawnEnemy();
  if ( m_player.takeDamage( player_dealt_damage ) <= 0)
  {
    gameOver();
  }
}

void GameStateGameplay::startTickEvent()
{
  m_game_tick.incrementTick();
  constexpr std::array<int, 5> tick_thresholds { 150, 120, 90, 60, 30 };
  
  if (m_game_tick.hasHitTick( tick_thresholds[ RandomGeneration::NumberBetween(0, tick_thresholds.size() - 1) ] ))
  {
    resetEnemyOnTick();
  }
}

void GameStateGameplay::drawGameUi()
{
  constexpr int ui_text_offset { 10 };
  constexpr int health_vertical_offset { ui_text_offset + 10 };
  constexpr int font_size { 32 }; 

  TextRender::drawTextToScreen 
  ( 
    std::format("Score: {}",  std::to_string(m_player.current_score)), 
    ui_text_offset, 
    ui_text_offset, 
    font_size 
  ); 

  TextRender::drawTextToScreen 
  ( 
    std::format("Health: {}", std::to_string( m_player.m_health.m_current_health )), 
    ui_text_offset, 
    ui_text_offset + 40, 
    font_size 
  ); 
}

void GameStateGameplay::gameOver()
{
  //m_game_manager->changeCurrentGameState( GameManager::GameType::splash );
  m_game_manager->closeGame();
}
