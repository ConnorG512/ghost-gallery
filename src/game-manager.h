#pragma once

#include "window.h"
#include "gamestate/gamestate-base.h"
#include "score-manager.h"

#include <memory>

struct GameManager
{
  GameManager();

  enum class GameType 
  {
    gameplay,
    splash,
  };

  void initGameState();
  void startGameLoop();
  bool shouldGameClose();
  void changeCurrentGameState( GameType gamestate );
  
  private:
    Window m_game_window;
    std::unique_ptr<GameState> m_current_gamestate { nullptr };
    ScoreManager m_score_manager {}; 
};
