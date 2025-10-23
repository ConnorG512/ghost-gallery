#include "gamestate-gameplay.h"
#include "../entities/player.h"
#include "../game-manager.h"
#include "../window.h"
#include "gamestate-base.h"

GameStateGameplay::GameStateGameplay(GameManager* game_manager,
                                     Window& game_window,
                                     Player& current_player,
                                     AudioManager& audio_manager)
    : GameState{game_manager, game_window, current_player, audio_manager}
{
    m_game_window.changeCursorStatus(Window::CursorStatus::hide);
    m_current_player.ResetPlayerStats();
    audio_manager.playAudio(AudioManager::SoundId::start_game);
};

void GameStateGameplay::initialiseState() {}

void GameStateGameplay::gameplayLoop()
{
    m_collectable_spawn_manager.checkForReady();
    if (m_current_player.health_component.GetHealth() == 0)
    {
        gameOver();
        return;
    }
    playerCollisionActions();

    m_enemy_spawn_manager.requestEnemySpawn(m_current_player.score_component.current_score);
    m_current_player.takeDamage(m_enemy_spawn_manager.attackPlayer(), m_audio_manager);
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

void GameStateGameplay::playerCollisionActions()
{
    if (m_collectable_spawn_manager.checkPlayerCollision(m_current_player, m_audio_manager))
    {
        m_current_player.changeCursorState(Player::CursorType::friendly);
    }
    else if (m_enemy_spawn_manager.checkPlayerCollision(m_current_player, m_audio_manager))
    {
        m_current_player.changeCursorState(Player::CursorType::enemy);
    }
    else
    {
        m_current_player.changeCursorState(Player::CursorType::neutral);
    }
}
