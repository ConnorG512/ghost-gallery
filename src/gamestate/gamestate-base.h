#pragma once

#include "../window.h"

class GameState 
{
  public:
    GameState( Window& game_window );
    virtual ~GameState();
    virtual void inputLoop() = 0;
    virtual void gameplayLoop() = 0;

  private:
    Window& m_game_window;
};
