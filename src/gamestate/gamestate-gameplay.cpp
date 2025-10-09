#include "gamestate-gameplay.h"
#include "gamestate-base.h"
#include "../text-render.h"
#include "../window.h"
#include "../input-handler.h"
#include <array>
#include <format>
#include <raylib.h>
#include <string>

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
  startTickEvent( determineGameRound());
  playerShoot();
}

void GameStateGameplay::gameplayLoop()
{
  m_game_window.beginDraw();
  m_game_window.clearWindow();

  m_background_image.drawSprite( 0 );
  m_enemy_sprite.drawToScreen( 0 );

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
  m_enemy_sprite.drawToScreen(
    0,
    RandomGeneration::NumberBetween( 200, 1400 ),
    RandomGeneration::NumberBetween( 100, 800 )
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
  m_player.takeDamage( player_dealt_damage );
}

void GameStateGameplay::startTickEvent( GameStateGameplay::CurrentGameRound current_round )
{
  m_game_tick.incrementTick();
  constexpr std::array<int, 5> round_tick_thresholds { 150, 120, 90, 60, 30 };
  int tick_threshold;

  switch ( current_round ) 
  {
    case CurrentGameRound::first:
      tick_threshold = round_tick_thresholds[0];
      break;
    case CurrentGameRound::second:
      tick_threshold = round_tick_thresholds[1];
      break;
    case CurrentGameRound::third:
      tick_threshold = round_tick_thresholds[2];
      break;
    case CurrentGameRound::fourth:
      tick_threshold = round_tick_thresholds[3];
      break;
    case CurrentGameRound::fifth:
      tick_threshold = round_tick_thresholds[4];
      break;
  }

  if (m_game_tick.hasHitTick( tick_threshold ))
  {
    resetEnemyOnTick();
  }
}

GameStateGameplay::CurrentGameRound GameStateGameplay::determineGameRound()
{
  constexpr std::array<int, 5> score_thresholds_for_round_change { 100, 200, 300, 400, 500 };

  if ( m_player.current_score < score_thresholds_for_round_change[0] )
  {
    return static_cast<GameStateGameplay::CurrentGameRound>(score_thresholds_for_round_change[0] / 100 );
  }
  if ( m_player.current_score < score_thresholds_for_round_change[1] )
  {
    return GameStateGameplay::CurrentGameRound::second;
  }
  if ( m_player.current_score < score_thresholds_for_round_change[2] )
  {
    return GameStateGameplay::CurrentGameRound::third;
  }
  if ( m_player.current_score < score_thresholds_for_round_change[3] )
  {
    return GameStateGameplay::CurrentGameRound::fourth;
  }
  if ( m_player.current_score < score_thresholds_for_round_change[4] || m_player.current_score > score_thresholds_for_round_change[4])
  {
    return GameStateGameplay::CurrentGameRound::fifth;
  } 
  else 
  {
    return GameStateGameplay::CurrentGameRound::fifth;
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
