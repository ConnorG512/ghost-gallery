#pragma once

#include <memory>

class GameManager;
class Window;
class Player;
class AudioManager;

class GameState
{
  public:
    GameState(GameManager* game_manager, Window& game_window, Player& current_player, AudioManager& audio_manager);
    virtual ~GameState() = default;

    virtual void initialiseState() = 0;
    virtual void gameplayLoop() = 0;
    virtual void renderingLoop() = 0;

  protected:
    GameManager* m_game_manager;
    Window& m_game_window;
    Player& m_current_player;
    AudioManager& m_audio_manager;
};
