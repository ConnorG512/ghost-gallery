#pragma once

#include "audio-manager.h"
#include "window.h"
#include "gamestate/gamestate-base.h"
#include "entities/player.h"

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
    Window m_game_window { 1600, 896, 60 };
    std::unique_ptr<GameState> m_current_gamestate { nullptr };
    AudioManager m_audio_manager {};
    
    Player m_current_player 
    { 
      { 
        "assets/image/ui/cursor-target.png", 
        "assets/image/ui/cursor-target-found.png", 
        "assets/image/ui/cursor-target-found-friendly.png" 
      },
      8, 
      8, 
    };
};
