#include "game-manager.h"
#include "gamestate/gamestate-base.h"
#include "gamestate/gamestate-gameplay.h"
#include "gamestate/gamestate-splash.h"
#include "window.h"
#include <cassert>
#include <memory>


namespace 
{
  constexpr int window_width { 1600 };
  constexpr int window_height { 900 };
  constexpr int target_framerate { 60 };
}

GameManager::GameManager()
  : m_game_window( window_width, window_height, target_framerate )
  , m_current_gamestate { std::make_unique<GameStateSplash>( m_game_window )} {}

void GameManager::initGameState()
{
  m_current_gamestate->initialiseState();
}

void GameManager::startGameLoop() 
{
  initGameState();

  while ( !shouldGameClose() ) 
  {
    assert( m_current_gamestate );
    m_current_gamestate->inputLoop();
    m_current_gamestate->gameplayLoop();
  }
}

bool GameManager::shouldGameClose() 
{
  return m_game_window.shouldWindowClose();
}

void GameManager::changeCurrentGameState( GameType gamestate ) 
{
  switch ( gamestate ) 
  {
    case GameType::splash:
      m_current_gamestate = std::make_unique<GameStateSplash>( m_game_window );
    case GameType::gameplay:
      m_current_gamestate = std::make_unique<GameStateGameplay>( m_game_window );
  }
}
