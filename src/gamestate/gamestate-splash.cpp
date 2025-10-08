#include "gamestate-splash.h"
#include "../text-render.h"
#include "../input-handler.h"
#include "../window.h"
#include "../game-manager.h"
#include <iostream>

GameStateSplash::GameStateSplash( GameManager* game_manager, Window& game_window )
  : GameState { game_manager, game_window } {}

void GameStateSplash::initialiseState() 
{
  // TODO
}

void GameStateSplash::inputLoop()
{
  // TODO
  if ( InputHandler::leftMousePressed() )
  {
    std::cout << "Ready to play!" << std::endl;
    startGameplayLoop();
  }
}

void GameStateSplash::gameplayLoop()
{
  // TODO
  m_game_window.beginDraw();
  m_game_window.clearWindow();
  
  TextRender::drawTextToScreen( "Press left mouse...", 1600 / 2 , 900 / 2, 32 );

  m_game_window.endDraw();
}

void GameStateSplash::startGameplayLoop()
{
  m_game_manager->changeCurrentGameState( GameManager::GameType::gameplay );
};
