#pragma once

#include <memory>

class GameManager;
class Window;

class GameState 
{
  public:
    GameState( Window& game_window );
    virtual ~GameState();
    virtual void initialiseState() = 0;
    virtual void inputLoop() = 0;
    virtual void gameplayLoop() = 0;

  protected:
    GameManager* m_game_manager;
    Window& m_game_window;
};
