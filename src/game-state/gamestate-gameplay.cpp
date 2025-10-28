#include "game-state/gamestate-gameplay.h"
#include "entity/player.h"
#include "game-state/gamestate-base.h"
#include "manager/game-manager.h"
#include "manager/window-manager.h"

GameStateGameplay::GameStateGameplay(GameManager* game_manager,
                                     WindowManager& game_window,
                                     Player& current_player,
                                     AudioManager& audio_manager)
    : GameState{game_manager, game_window, current_player, audio_manager}
{
    m_game_window.changeCursorStatus(WindowManager::CursorStatus::hide);
    m_current_player.ResetPlayerStats();
    audio_manager.playAudio(AudioManager::SoundId::start_game);
};

void GameStateGameplay::initialiseState() {}

void GameStateGameplay::gameplayLoop()
{
    m_collectable_spawn_manager.checkForReady(m_game_window.GetWindowSize());
    if (m_current_player.health_component.GetHealth() == 0)
    {
        gameOver();
        return;
    }
    m_current_player.changeCursorState(Player::CursorType::neutral);
    m_collectable_spawn_manager.checkPlayerCollision(m_current_player, m_audio_manager);
    m_enemy_spawn_manager.requestEnemySpawn(m_current_player.score_component.current_score,
                                            m_game_window.GetWindowSize());
    m_enemy_spawn_manager.checkPlayerCollision(m_current_player, m_audio_manager);
    m_enemy_spawn_manager.attackPlayer(m_current_player, m_audio_manager);
    m_enemy_spawn_manager.increaseEnemyAmount(m_current_player.score_component.current_score);
}

void GameStateGameplay::renderingLoop()
{
    m_game_window.beginDraw();
    m_game_window.drawAndClear();

    // Drawing Sprites
    m_background_image.drawSprite();
    m_collectable_spawn_manager.drawCollectables();
    m_enemy_spawn_manager.drawEnemySprites();
    m_current_player.drawPlayerCursor();

    // UI
    m_ui.drawUi({
        m_current_player.score_component.current_score,
        m_current_player.health_component.GetHealth(),
        m_current_player.score_component.current_multiplier,
    });

    m_game_window.endDraw();
}

void GameStateGameplay::gameOver()
{
    m_current_player.score_component.checkForNewHighScore();
    m_game_manager->changeCurrentGameState(GameManager::GameType::splash);
}
