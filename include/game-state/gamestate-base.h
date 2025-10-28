#pragma once

class GameManager;
class WindowManager;
class Player;
class AudioManager;

class GameState
{
  public:
    virtual ~GameState() = default;

    virtual void initialiseState() = 0;
    virtual void gameplayLoop() = 0;
    virtual void renderingLoop() = 0;
  
  protected:
    GameState(GameManager* game_manager, WindowManager& game_window, Player& current_player, AudioManager& audio_manager);

    GameManager* m_game_manager;
    WindowManager& m_game_window;
    Player& m_current_player;
    AudioManager& m_audio_manager;
};
