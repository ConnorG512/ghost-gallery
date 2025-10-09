#pragma once

#include "window.h"
#include "gamestate/gamestate-base.h"
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
  void closeGame();
  
  private:
    Window m_game_window;
    std::unique_ptr<GameState> m_current_gamestate { nullptr };
};
