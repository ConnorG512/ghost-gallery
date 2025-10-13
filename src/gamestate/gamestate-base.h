#pragma once

#include <memory>

class GameManager;
class Window;
class ScoreManager;
class AudioManager;

class GameState 
{
  public:
    GameState( GameManager* game_manager, Window& game_window, ScoreManager& score_manager, AudioManager& audio_manager );
    virtual ~GameState();
    virtual void initialiseState() = 0;
    virtual void inputLoop() = 0;
    virtual void gameplayLoop() = 0;

  protected:
    GameManager* m_game_manager;
    Window& m_game_window;
    ScoreManager& m_score_manager;
    AudioManager& m_audio_manager;
};
