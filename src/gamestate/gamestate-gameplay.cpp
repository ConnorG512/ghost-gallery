#include "gamestate-gameplay.h"
#include "gamestate-base.h"
#include "../window.h"
#include "../game-manager.h"
#include "../input-handler.h"
#include <array>

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

namespace { }

void GameStateGameplay::initialiseState() { }

void GameStateGameplay::inputLoop() 
{
  onEnemyClicked();
  m_collectable_spawn_manager.checkForPlayerCollision( m_current_player );
}

void GameStateGameplay::gameplayLoop()
{
  m_game_window.beginDraw();
  m_game_window.clearWindow();
  
  onGameTicks();
  m_background_image.drawSprite();
  m_collectable_spawn_manager.drawCollectables();
  m_enemy.sprite.drawSprite();
  m_current_player.moveSprite(InputHandler::GetMousePosX(), InputHandler::GetMousePosY());

  m_game_ui.drawAll
  (
   { 
     m_current_player.score_component.current_score,
     m_current_player.health_component.current_health,
     m_current_player.score_component.current_multiplier
   }
  );

  m_game_window.endDraw();
}

GameStateGameplay::~GameStateGameplay()
{
  m_current_player.score_component.checkForNewHighScore(); 
}

void GameStateGameplay::onGameTicks()
{
  m_game_tick.incrementTick();
  constexpr std::array<int, 2> tick_thresholds { 60, 180 };
  if ( m_game_tick.hasHitTick( tick_thresholds.at( 0 )))
  {
    m_current_player.health_component.reduceHealth( m_enemy.damage_component.CalculateDamage());
    m_enemy.moveLocation();
  }
  else if ( m_game_tick.hasHitTick( tick_thresholds.at( 1 )))
  {
    m_collectable_spawn_manager.requestCollectable();
  } 
}

void GameStateGameplay::onEnemyClicked()
{
  if ( m_enemy.hasCollidedWithPlayer( m_current_player ) && InputHandler::receiveInput() == InputHandler::ButtonPress::left_mouse )
  {
    m_enemy.moveLocation();
    m_current_player.score_component.increaseScore( m_enemy.score_to_give );

    if ( RandomGeneration::HasHitThreshold(RandomGeneration::NumberBetween(), 15))
    {
      m_collectable_spawn_manager.requestCollectable();
    }
    m_audio_manager.playAudio( AudioManager::SoundId::ghost_death );
  }
}
