#include "spawn-manager-enemy.h"
#include "../entities/components/health-component.h"
#include "../entities/enemy.h"
#include "../entities/player.h"
#include "../util/random-generation.h"
#include "../util/utils.h"

#include <algorithm>
#include <array>
#include <cassert>
#include <memory>
#include <ranges>

SpawnManagerEnemy::SpawnManagerEnemy(const int num_spawn_slots) : SpawnManager{num_spawn_slots}
{
    m_enemy_list.resize(m_num_available_slots);
}

void SpawnManagerEnemy::requestEnemySpawn(const int& current_game_score)
{
    for (auto& current_enemy_slot : m_enemy_list)
    {
        if (!Utils::IsValidUniquePtr(current_enemy_slot))
        {
            current_enemy_slot = createEnemy();
            assert(current_enemy_slot != nullptr && "Enemy slot should not be nullptr!");
        }
    }
}

void SpawnManagerEnemy::drawEnemySprites()
{
    std::ranges::for_each(m_enemy_list | std::views::filter([](std::unique_ptr<Enemy>& enemy_instance)
                                                            { return Utils::IsValidUniquePtr(enemy_instance); }),
                          [&](std::unique_ptr<Enemy>& enemy_instance)
                          { enemy_instance->sprite.drawSprite(enemy_instance->positional_component.GetXYPos()); });
}

void SpawnManagerEnemy::attackPlayer(HealthComponent& player_health)
{
    std::ranges::for_each(m_enemy_list | std::views::filter([](std::unique_ptr<Enemy>& enemy_instance)
                                                            { return Utils::IsValidUniquePtr(enemy_instance); }),
                          [&](const std::unique_ptr<Enemy>& enemy_instance)
                          { player_health.ReduceHealthBy(enemy_instance->InitiateAttack()); });
}

void SpawnManagerEnemy::moveEntitiesToNewPos()
{
    for (auto& current_enemy_slot : m_enemy_list)
        if (current_enemy_slot != nullptr)
        {
            current_enemy_slot->setNewEntityPosition();
        }
}

bool SpawnManagerEnemy::checkPlayerCollision(Player& current_player, AudioManager& audio_manager)
{
    bool has_player_collided{false};

    std::ranges::for_each(
        m_enemy_list |
            std::views::filter([](std::unique_ptr<Enemy>& enemy_instance)
                               { return Utils::IsValidUniquePtr(enemy_instance); }) |
            std::views::filter(
                [&current_player](std::unique_ptr<Enemy>& enemy_instance)
                { return enemy_instance->collision.IsCollidingWith(current_player.collision.GetCollisionPosition()); }),
        [&](std::unique_ptr<Enemy>& enemy_instance)
        {
            has_player_collided = true;
            if (current_player.user_input.UserAction() == UserInput::InputAction::fire)
            {
                current_player.score_component.increaseScore(enemy_instance->score_to_give);
                enemy_instance->playSound(audio_manager);
                enemy_instance.reset();
            }
        });

    return has_player_collided;
}

std::unique_ptr<Enemy> SpawnManagerEnemy::createEnemy()
{
    constexpr std::pair<int, int> screen_range_x{200, 1400};
    constexpr std::pair<int, int> screen_range_y{200, 600};
    constexpr std::pair<int, int> base_damage_thresholds{1, 3};
    constexpr std::pair<int, int> critical_chance_thresholds{1, 10};
    constexpr std::pair<int, int> given_score_thresholds{200, 650};
    constexpr std::pair<int, int> tick_thresholds{65, 120};

    return std::make_unique<Enemy>(
        std::array<int, 2>{RandomGeneration::GenerateRandomNumber(screen_range_x.first, screen_range_x.second),
                           RandomGeneration::GenerateRandomNumber(screen_range_y.first, screen_range_y.second)},
        RandomGeneration::GenerateRandomNumber(base_damage_thresholds.first, base_damage_thresholds.second),
        RandomGeneration::GenerateRandomNumber(critical_chance_thresholds.first, critical_chance_thresholds.second),
        RandomGeneration::GenerateRandomNumber(given_score_thresholds.first, given_score_thresholds.second),
        RandomGeneration::GenerateRandomNumber(tick_thresholds.first, tick_thresholds.second));
}
