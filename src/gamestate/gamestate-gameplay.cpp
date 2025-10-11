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

  drawSprites();
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
  else if ( m_player.checkCollision( m_heart_collectable.getCollision()) && m_heart_collectable.isHeartActive() )
  {
    m_player.changePlayerCursor(Player::TextureName::targeted_friendly, m_game_window );
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
  if ( InputHandler::receiveInput() == InputHandler::ButtonPress::left_mouse && m_player.checkCollision( m_enemy_sprite.getCollision()))
  {
    if (m_enemy_sprite.takeDamage(m_player.fire_damage) <= 0 )
    {
      m_game_tick.resetTickCounter();
      respawnEnemy();
      m_score_manager.increaseScore( score_amount_to_add ); 
      spawnHeartCollectable();
    }
  }
  else if ( InputHandler::receiveInput() == InputHandler::ButtonPress::left_mouse && m_player.checkCollision( m_heart_collectable.getCollision()))
  {
    m_player.recieveHealth( m_heart_collectable.giveHealth());
    drawGameUi();
    m_heart_collectable.deactivatePickup();
  }
}

void GameStateGameplay::resetEnemyOnTick()
{
  respawnEnemy();
  if ( m_player.takeDamage( m_enemy_sprite.dealDamage() ) <= 0)
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

  TextRender::drawTextToScreen 
  ( 
    std::format("Score: {}",  std::to_string(m_score_manager.m_current_score)), 
    ui_text_offset, 
    ui_text_offset
  ); 

  TextRender::drawTextToScreen 
  ( 
    std::format("Health: {}", std::to_string( m_player.m_health.m_current_health )), 
    ui_text_offset, 
    ui_text_offset + 40 
  ); 
}

void GameStateGameplay::gameOver()
{
  //m_game_manager->changeCurrentGameState( GameManager::GameType::splash );
  m_game_manager->closeGame();
}

void GameStateGameplay::drawSprites()
{
  m_heart_collectable.drawToScreen();
  m_enemy_sprite.drawToScreen( 0 );
}

void GameStateGameplay::playerClickedHeartPickup()
{
  m_player.recieveHealth( m_heart_collectable.giveHealth());
}

void GameStateGameplay::spawnHeartCollectable()
{
  if ( !m_heart_collectable.isHeartActive() )
  {
    int random_result { RandomGeneration::NumberBetween( 1, 100)};
    constexpr int success_threshold { 50 };
    
    if (random_result >= success_threshold )
    {
      m_heart_collectable.moveAndActivateToNewLocation();
    }
  }
}
