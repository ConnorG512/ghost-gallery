#include "spawn-manager-enemy.h"
#include "../entities/enemy.h"
#include "../util/random-generation.h"

#include <array>
#include <memory>

SpawnManagerEnemy::SpawnManagerEnemy(const int tick_threshold,
                                     const int num_spawn_slots)
    : SpawnManager{tick_threshold, num_spawn_slots}
{
    m_enemy_list.resize(m_num_available_slots);
}

void SpawnManagerEnemy::requestEnemySpawn()
{
    for (auto &current_enemy_slot : m_enemy_list)
    {
        if (current_enemy_slot == nullptr)
        {
            current_enemy_slot = createEnemy();
        }
    }
}

std::unique_ptr<Enemy> SpawnManagerEnemy::createEnemy()
{
    constexpr std::array<int, 5> attack_thresholds{30, 50, 80, 100, 120};
    constexpr std::array<std::pair<int, int>, 2> spawn_screen_positions{
        {{200, 1400}, {200, 600}}};
    constexpr std::pair<int, int> base_damage_thresholds{2, 4};
    constexpr std::pair<int, int> critical_chance_thresholds{1, 25};
    constexpr std::pair<int, int> given_score_thresholds{200, 650};

    return std::make_unique<Enemy>(
        std::array<int, 2>{RandomGeneration::GenerateRandomNumber(
                               spawn_screen_positions.at(0).first,
                               spawn_screen_positions.at(0).second),
                           RandomGeneration::GenerateRandomNumber(
                               spawn_screen_positions.at(1).first,
                               spawn_screen_positions.at(1).second)},
        RandomGeneration::GenerateRandomNumber(
            RandomGeneration::GenerateRandomNumber(
                base_damage_thresholds.first, base_damage_thresholds.second)),
        RandomGeneration::GenerateRandomNumber(
            RandomGeneration::GenerateRandomNumber(
                critical_chance_thresholds.first,
                critical_chance_thresholds.second)),
        RandomGeneration::GenerateRandomNumber(given_score_thresholds.first,
                                               given_score_thresholds.second),
        attack_thresholds.at(RandomGeneration::GenerateRandomNumber(
            0, attack_thresholds.size() - 1)));
}
