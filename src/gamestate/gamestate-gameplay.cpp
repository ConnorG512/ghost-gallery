#include "gamestate-gameplay.h"
#include "gamestate-base.h"
#include "../window.h"
#include "../game-manager.h"
#include "../input-handler.h"

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
  m_current_player.score_component.resetScore();
};

namespace { }

void GameStateGameplay::initialiseState() { }

void GameStateGameplay::inputLoop() 
{
  m_collectable_spawn_manager.checkForPlayerCollision( m_current_player );
}

void GameStateGameplay::gameplayLoop()
{
  m_game_window.beginDraw();
  m_game_window.clearWindow();
  
  onGameTicks();
  m_background_image.drawSprite();
  m_collectable_spawn_manager.drawCollectables();
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
  if ( m_game_tick.hasHitTick( 180 ))
  {
    m_collectable_spawn_manager.requestCollectable();
  } 
}
