#pragma once 

#include "gamestate-base.h"

class GameStateSplash : public GameState 
{
  public:
    GameStateSplash(GameManager* game_manager, Window& game_window );
    
    void initialiseState() override;
    void inputLoop() override;
    void gameplayLoop() override;

  protected:

};
