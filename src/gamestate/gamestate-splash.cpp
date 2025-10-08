#include "gamestate-splash.h"
#include "../text-render.h"
#include "../input-handler.h"
#include "../window.h"
#include <iostream>

GameStateSplash::GameStateSplash( Window& game_window )
  : GameState { game_window } {}

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
