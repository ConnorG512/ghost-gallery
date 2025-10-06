#pragma once

#include "gamestate-base.h"

class GameStateGameplay : public GameState
{
  public: 
    GameStateGameplay( Window& game_window );
    void inputLoop() override;
    void gameplayLoop() override;
};
