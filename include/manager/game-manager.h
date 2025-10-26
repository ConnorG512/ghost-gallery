#pragma once

#include "manager/audio-manager.h"
#include "entity/player.h"
#include "game-state/gamestate-base.h"
#include "manager/window-manager.h"

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
    void changeCurrentGameState(GameType gamestate);

  private:
    WindowManager m_game_window{1600, 896, 60};
    std::unique_ptr<GameState> m_current_gamestate{nullptr};
    AudioManager m_audio_manager{};

    Player m_current_player{
        8,
        8,
    };
};
