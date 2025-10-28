#include "entity/enemy.h"
#include "component/damage-component.h"
#include "component/user-input-component.h"
#include "entity/entity.h"
#include "entity/player.h"
#include "manager/audio-manager.h"
#include "util/random-generation.h"

#include <array>
#include <vector>

namespace
{
constexpr std::array<int, 2> score_range{25, 75};
}

Enemy::Enemy(const std::vector<std::string>& texture_paths,
             const std::array<int, 2> xy_pos,
             const int base_damage,
             const int critical_chance,
             const int given_score,
             const int tick_threshold)
    : Entity{texture_paths, 2, 2, xy_pos.at(0), xy_pos.at(1)}, damage_component{base_damage, critical_chance},
      score_to_give{given_score}, m_tick_component{tick_threshold}
{
}

void Enemy::respawnEnemy()
{
    setNewEntityPosition(
        {RandomGeneration::GenerateRandomNumber(100, 1400), RandomGeneration::GenerateRandomNumber(200, 750)});
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

void Enemy::playSound(AudioManager& audio_manager) { audio_manager.playAudio(AudioManager::SoundId::ghost_death); }

void Enemy::initiateAttack(Player& current_player, AudioManager& audio_manager)
{
    if (m_tick_component.IncrementAndCheckThreshold())
    {
        current_player.takeDamage(damage_component.CalculateDamage(), audio_manager);
        respawnEnemy();
        m_tick_component.resetTickCount();
    }
}
