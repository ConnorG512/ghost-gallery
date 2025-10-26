#include "game-state/gamestate-splash.h"
#include "component/user-input-component.h"
#include "manager/game-manager.h"
#include "window.h"

GameStateSplash::GameStateSplash(GameManager* game_manager,
                                 Window& game_window,
                                 Player& current_player,
                                 AudioManager& audio_manager)
    : GameState{game_manager, game_window, current_player, audio_manager}
{
    m_game_window.changeCursorStatus(Window::CursorStatus::show);
}

void GameStateSplash::initialiseState()
{
    // TODO
}

void GameStateSplash::gameplayLoop()
{
    using enum UserInput::InputAction;
    if (m_current_player.user_input.UserAction() == start_game)
    {
        startGameplayLoop();
    }
}

void GameStateSplash::renderingLoop()
{
    m_game_window.beginDraw();
    m_game_window.drawAndClear();

    m_background_image.drawSprite();
    m_ui.drawUi(m_current_player.score_component.high_score);

    m_game_window.endDraw();
}

void GameStateSplash::startGameplayLoop() { m_game_manager->changeCurrentGameState(GameManager::GameType::gameplay); };
