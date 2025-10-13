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

GameStateGameplay::GameStateGameplay( GameManager* game_manager, Window& game_window, ScoreManager& score_manager, AudioManager& audio_manager )
  : GameState { game_manager, game_window, score_manager, audio_manager } 
{
  m_game_window.changeCursorStatus( Window::CursorStatus::hide );
  m_score_manager.resetCurrentScore();
};

namespace 
{
  constexpr int score_amount_to_add { 20 };
}

void GameStateGameplay::initialiseState() { }

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
  
  checkEntityCollisions();

  drawGameUi();

  m_game_window.endDraw();
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
    if (m_enemy_sprite.takeDamage(m_player.damage_component.CalculateDamage()) <= 0 )
    {
      m_game_tick.resetTickCounter();
      respawnEnemy();
      m_score_manager.increaseScore( score_amount_to_add ); 
      m_audio_manager.playAudio( AudioManager::SoundId::ghost_death );
      spawnCollectables();
    }
  }
  else if ( InputHandler::receiveInput() == InputHandler::ButtonPress::left_mouse && m_player.checkCollision( m_heart_collectable.getCollision()))
  {
    m_player.recieveHealth( m_heart_collectable.giveHealth());
    m_heart_collectable.setHidden( true );
    drawGameUi();
  }
  else if ( InputHandler::receiveInput() == InputHandler::ButtonPress::left_mouse && m_player.checkCollision( m_coin_collectable.getCollision()))
  {
    m_score_manager.increaseScore(m_coin_collectable.GivePoints( m_score_manager ));
    m_coin_collectable.setHidden( true );
    drawGameUi();
  }
}

bool GameStateGameplay::hasPlayerDied()
{
  if ( m_player.takeDamage( m_enemy_sprite.damage_component.CalculateDamage( m_score_manager )) <= 0)
  {
    return true;
  }
  return false;
}

void GameStateGameplay::resetEnemyOnTick()
{
  respawnEnemy();
  if ( hasPlayerDied())
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
  constexpr int health_vertical_offset { ui_text_offset + 40 };

  TextRender::drawTextToScreen 
  ( 
    std::format("Score: {}",  std::to_string(m_score_manager.current_score)), 
    ui_text_offset, 
    ui_text_offset
  ); 

  TextRender::drawTextToScreen 
  ( 
    std::format("Health: {}", std::to_string( m_player.m_health.m_current_health )), 
    ui_text_offset, 
    health_vertical_offset 
  ); 
}

void GameStateGameplay::gameOver()
{
  m_game_manager->changeCurrentGameState( GameManager::GameType::splash );
}

void GameStateGameplay::drawSprites()
{
  m_heart_collectable.drawToScreen();
  m_coin_collectable.drawToScreen();
  m_enemy_sprite.drawToScreen();
}

void GameStateGameplay::playerClickedHeartPickup()
{
  m_player.recieveHealth( m_heart_collectable.giveHealth());
}

void GameStateGameplay::spawnCollectables()
{
  if ( m_heart_collectable.isHidden() )
  {
    constexpr int success_threshold { 5 };
    if ( RandomGeneration::HasHitThreshold( RandomGeneration::NumberBetween( 1, 100 ), success_threshold ))
    {
      m_heart_collectable.moveAndActivateToNewLocation();
    }
  }
  if ( m_coin_collectable.isHidden())
  {
    constexpr int success_threshold { 15 };
    if ( RandomGeneration::HasHitThreshold( RandomGeneration::NumberBetween( 1, 100 ), success_threshold ))
    {
      m_coin_collectable.respawnToNewLocation();
    }
  }
}

void GameStateGameplay::checkEntityCollisions()
{
  if ( m_player.checkCollision( m_enemy_sprite.getCollision()))
  {
    m_player.changePlayerCursor( m_game_window, m_enemy_sprite );
  }
  else if ( m_player.checkCollision(m_heart_collectable.getCollision()) && !m_heart_collectable.isHidden())
  {
    m_player.changePlayerCursor( m_game_window, m_heart_collectable );
  }
  else if ( m_player.checkCollision(m_coin_collectable.getCollision()) && !m_coin_collectable.isHidden())
  {
    m_player.changePlayerCursor( m_game_window, m_coin_collectable );
  }
  else {
    m_player.changePlayerCursor( m_game_window );
  }
}
