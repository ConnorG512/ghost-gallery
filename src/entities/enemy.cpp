#include "enemy.h"
#include "../audio-manager.h"
#include "../random-generation.h"
#include "components/user-input-component.h"
#include "entity.h"
#include "player.h"

#include <array>
#include <ranges>

namespace
{
constexpr std::array<int, 2> score_range{25, 75};
}

Enemy::Enemy(const int x_pos, const int y_pos)
    : Entity{{"assets/image/entity/enemy/ghost/ghost-1.png"},
             2,
             2,
             x_pos,
             y_pos},
      score_to_give{
          RandomGeneration::NumberBetween(score_range.at(0), score_range.at(1))}
{
}

void Enemy::respawnEnemy()
{
    setNewEntityPosition({RandomGeneration::NumberBetween(100, 1400),
                          RandomGeneration::NumberBetween(200, 750)});
    changeEnemyGivenScore();
    m_tick_component.resetTickCount();
}

void Enemy::collidedWithPlayer(Player &current_player,
                               AudioManager &audio_manager)
{
    if (collision.IsCollidingWith(
            current_player.collision.GetCollisionPosition()))
    {
        current_player.drawPlayerCursor(Player::CursorType::enemy);
        if (current_player.user_input.UserAction() ==
            UserInput::InputAction::fire)
        {
            respawnEnemy();
            current_player.score_component.increaseScore(score_to_give);
            playSound(audio_manager);
        }
    }
}

void Enemy::changeEnemyGivenScore()
{
    score_to_give =
        RandomGeneration::NumberBetween(score_range.at(0), score_range.at(1));
}

void Enemy::playSound(AudioManager &audio_manager)
{
    audio_manager.playAudio(AudioManager::SoundId::ghost_death);
}

int Enemy::InitiateAttack(const int &current_game_score)
{
    setAggression(current_game_score);
    if (m_tick_component.IncrementAndCheckThreshold())
    {
        respawnEnemy();
        return damage_component.CalculateDamage();
    }
    return 0;
}

void Enemy::setAggression(const int &current_game_score)
{
    constexpr std::array<int, 8> score_thresholds{500,  1500,  3000,  6000,
                                                  9000, 18000, 36000, 72000};
    constexpr std::array<int, 8> attack_tick_speed{120, 100, 75, 60,
                                                   50,  40,  35, 20};
    static_assert(
        score_thresholds.size() == attack_tick_speed.size(),
        "score_thresholds and attack_tick_speed must be the same size!");

    for (auto [score_threshold, enemy_attack_speed] :
         std::views::zip(score_thresholds, attack_tick_speed))
    {
        if (current_game_score >= score_threshold)
        {
            m_tick_component.setNewTickThreshold(enemy_attack_speed);
        }
    }
}
