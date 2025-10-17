#include "gamestate-gameplay.h"
#include "gamestate-base.h"
#include "../window.h"
#include "../game-manager.h"
#include "../entities/player.h"

GameStateGameplay::GameStateGameplay
( 
  GameManager* game_manager, 
  Window& game_window, 
  Player& current_player, 
  AudioManager& audio_manager 
)
  : GameState { game_manager, game_window, current_player, audio_manager } 
{
  m_game_window.changeCursorStatus( Window::CursorStatus::hide );
  m_current_player.ResetPlayerStats();
};

void GameStateGameplay::initialiseState() { }

void GameStateGameplay::inputLoop() 
{
  m_collectable_spawn_manager.checkForReady();
  m_enemy.incrementAttackClock( m_current_player );

  if ( m_current_player.health_component.current_health == 0 )
  {
    gameOver();
  }
}

void GameStateGameplay::gameplayLoop()
{
  m_game_window.beginDraw();
  m_game_window.clearWindow();
  m_background_image.drawSprite();
  m_enemy.sprite.drawSprite();

  m_current_player.drawPlayerCursor( Player::CursorType::neutral );
  m_enemy.collidedWithPlayer( m_current_player, m_audio_manager );
  
  m_collectable_spawn_manager.drawCollectables();
  m_collectable_spawn_manager.checkForPlayerInteraction( m_current_player, m_audio_manager );
  
  m_ui.drawUi(
  {
    m_current_player.score_component.current_score,
    m_current_player.health_component.current_health,
    m_current_player.score_component.current_multiplier,
  });

  m_game_window.endDraw();
}

void GameStateGameplay::gameOver()
{
  m_current_player.score_component.checkForNewHighScore(); 
  m_game_manager->changeCurrentGameState( GameManager::GameType::splash );
}

