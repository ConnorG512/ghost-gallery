#include "gamestate-splash.h"
#include "../text-render.h"
#include "../window.h"
#include "../game-manager.h"
#include "../entities/components/user-input-component.h"
#include <format>
#include <raylib.h>
#include <string>

GameStateSplash::GameStateSplash( GameManager* game_manager, Window& game_window, Player& current_player, AudioManager& audio_manager )
  : GameState { game_manager, game_window, current_player, audio_manager }
{
  m_game_window.changeCursorStatus( Window::CursorStatus::show );
}

void GameStateSplash::initialiseState() 
{
  // TODO
}

void GameStateSplash::inputLoop()
{
  using enum UserInput::InputAction;
  if ( m_current_player.user_input.UserAction() == start_game )
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
  constexpr int edit_text_y_offset { 50 };
  constexpr int high_score_text_y_offset { 100 };

  const std::string& start_text { "Press space key to start..." };
  TextRender::drawTextToScreen
    ( 
    start_text, m_game_window.m_width / 2 - MeasureText(start_text.c_str(), 32 ) / 2, 
    m_game_window.m_height / 2, 
    font_size 
  );
  
  const std::string& exit_text { "Press escape to exit..." };
  TextRender::drawTextToScreen
    ( 
    exit_text, m_game_window.m_width / 2 - MeasureText(exit_text.c_str(), 32 ) / 2, 
    m_game_window.m_height / 2 + edit_text_y_offset, 
    font_size 
  );
  
  const std::string& high_score_text { "High Score:" };
  TextRender::drawTextToScreen
    ( 
    std::format("{} {}", high_score_text, std::to_string( 0 )), m_game_window.m_width / 2 - MeasureText(high_score_text.c_str(), 32 ) / 2, 
    m_game_window.m_height / 2 + high_score_text_y_offset, 
    font_size 
  );
}
