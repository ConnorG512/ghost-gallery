#include "gamestate-splash.h"
#include "../text-render.h"
#include "../input-handler.h"
#include "../window.h"
#include "../game-manager.h"
#include <raylib.h>

GameStateSplash::GameStateSplash( GameManager* game_manager, Window& game_window )
  : GameState { game_manager, game_window } 
{
  m_game_window.changeCursorStatus( Window::CursorStatus::show );
}

void GameStateSplash::initialiseState() 
{
  // TODO
}

void GameStateSplash::inputLoop()
{
  // TODO
  if ( InputHandler::receiveInput() == InputHandler::ButtonPress::space_key )
  {
    startGameplayLoop();
  }
}

void GameStateSplash::gameplayLoop()
{
  // TODO
  m_game_window.beginDraw();
  m_game_window.clearWindow();

  m_background_image.drawSprite( 0 );
  drawSplashText();

  m_game_window.endDraw();
}

void GameStateSplash::startGameplayLoop()
{
  m_game_manager->changeCurrentGameState( GameManager::GameType::gameplay );
};

void GameStateSplash::drawSplashText()
{
  constexpr int font_size { 32 };
  constexpr int screen_size_x { 1600 };
  constexpr int screen_size_y { 900 };

  const std::string& start_text { "Press space key to start..." };
  TextRender::drawTextToScreen( 
    start_text, screen_size_x / 2 - MeasureText(start_text.c_str(), 32 ) / 2, 
    screen_size_y / 2, 
    font_size 
  );
  
  const std::string& exit_text { "Press escape to exit..." };
  TextRender::drawTextToScreen( 
    exit_text, screen_size_x / 2 - MeasureText(exit_text.c_str(), 32 ) / 2, 
    screen_size_y / 2 + 50, 
    font_size 
  );
}
