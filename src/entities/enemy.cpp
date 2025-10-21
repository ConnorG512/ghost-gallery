#include "enemy.h"
#include "../audio-manager.h"
#include "../util/random-generation.h"
#include "components/damage-component.h"
#include "components/user-input-component.h"
#include "entity.h"
#include "player.h"

#include <array>
#include <cassert>

namespace
{
constexpr std::array<int, 2> score_range{25, 75};
}

Enemy::Enemy(const std::array<int, 2> xy_pos,
             const int base_damage,
             const int critical_chance,
             const int given_score,
             const int tick_threshold)
    : Entity{{"assets/image/entity/enemy/ghost/ghost-1.png"}, 2, 2, xy_pos.at(0), xy_pos.at(1)},
      damage_component{base_damage, critical_chance}, score_to_give{given_score}, m_tick_component{tick_threshold}
{
}

void Enemy::respawnEnemy()
{
    setNewEntityPosition(
        {RandomGeneration::GenerateRandomNumber(100, 1400), RandomGeneration::GenerateRandomNumber(200, 750)});
    changeEnemyGivenScore();
    m_tick_component.resetTickCount();
}

void Enemy::collidedWithPlayer(Player& current_player, AudioManager& audio_manager)
{
    if (collision.IsCollidingWith(current_player.collision.GetCollisionPosition()))
    {
        current_player.changeCursorState(Player::CursorType::enemy);
        if (current_player.user_input.UserAction() == UserInput::InputAction::fire)
        {
            respawnEnemy();
            current_player.score_component.increaseScore(score_to_give);
            playSound(audio_manager);
        }
    }
}

void Enemy::changeEnemyGivenScore()
{
    score_to_give = RandomGeneration::GenerateRandomNumber(score_range.at(0), score_range.at(1));
}

void Enemy::playSound(AudioManager& audio_manager) { audio_manager.playAudio(AudioManager::SoundId::ghost_death); }

int Enemy::InitiateAttack()
{
    if (m_tick_component.IncrementAndCheckThreshold())
    {
        respawnEnemy();
        m_tick_component.resetTickCount();
        int damage_result{damage_component.CalculateDamage()};
        assert(damage_result < 12 && "Damage recieved absurdly high!");
        return damage_component.CalculateDamage();
    }
    return 0;
}
