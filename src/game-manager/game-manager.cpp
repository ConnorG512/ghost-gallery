#include "include/manager/game-manager.h"
#include "incluce/game-state/gamestate/gamestate-base.h"
#include "incluce/game-state/gamestate/gamestate-gameplay.h"
#include "incluce/game-state/gamestate/gamestate-splash.h"
#include "include/window.h"

#include <cassert>
#include <memory>

GameManager::GameManager()
    : m_current_gamestate{std::make_unique<GameStateSplash>(this, m_game_window, m_current_player, m_audio_manager)}
{
}

void GameManager::initGameState() { m_current_gamestate->initialiseState(); }

void GameManager::startGameLoop()
{
    initGameState();

    while (!shouldGameClose())
    {
        assert(m_current_gamestate);

        m_current_player.user_input.decreaseVolume(m_audio_manager);
        m_current_player.user_input.increaseVolume(m_audio_manager);

        m_current_gamestate->gameplayLoop();
        m_current_gamestate->renderingLoop();
    }
}

bool GameManager::shouldGameClose() { return m_game_window.ShouldWindowClose(); }

void GameManager::changeCurrentGameState(GameType gamestate)
{
    switch (gamestate)
    {
        case GameType::splash:
            m_current_gamestate =
                std::make_unique<GameStateSplash>(this, m_game_window, m_current_player, m_audio_manager);
            break;
        case GameType::gameplay:
            m_current_gamestate =
                std::make_unique<GameStateGameplay>(this, m_game_window, m_current_player, m_audio_manager);
            break;
    }
}
