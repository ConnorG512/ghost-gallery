#include "game-manager.h"
#include "gamestate/gamestate-gameplay.h"
#include "window.h"
#include "gamestate/gamestate-base.h"
#include <cassert>
#include <memory>


namespace 
{
}

GameManager::GameManager()
  : m_game_window( 1600, 900, 60 )
  , m_current_gamestate { std::make_unique<GameStateGameplay>( m_game_window )} {}

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
