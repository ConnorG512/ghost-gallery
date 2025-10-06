#pragma once

#include "../window.h"
#include <memory>

class GameState 
{
  public:
    GameState( Window& game_window );
    virtual ~GameState();
    virtual void inputLoop() = 0;
    virtual void gameplayLoop() = 0;

  protected:
    Window& m_game_window;
};
