#include "manager/spawn-manager-enemy.h"
#include "entity/enemy.h"
#include "entity/player.h"
#include "util/random-generation.h"
#include "util/utils.h"

#include <algorithm>
#include <array>
#include <cassert>
#include <memory>
#include <ranges>
#include <utility>

SpawnManagerEnemy::SpawnManagerEnemy(const int num_spawn_slots) : SpawnManager{num_spawn_slots}
{
    m_enemy_list.resize(m_num_available_slots);
}

void SpawnManagerEnemy::requestEnemySpawn(const int& current_game_score, const std::pair<int, int> screen_xy)
{
    for (auto& current_enemy_slot :
         m_enemy_list | std::views::filter([this](const std::unique_ptr<Enemy>& enemy_instance)
                                           { return !Utils::IsValidUniquePtr(enemy_instance); }))
    {
        current_enemy_slot = createEnemy(screen_xy);
        assert(current_enemy_slot != nullptr && "Enemy slot should not be nullptr!");
    }
}

void SpawnManagerEnemy::drawEnemySprites()
{
    for (const auto& enemy_instance :
         m_enemy_list |
             std::views::filter([](const auto& enemy_instance) { return Utils::IsValidUniquePtr(enemy_instance); }))
    {
        enemy_instance->sprite.drawSprite(enemy_instance->positional_component.GetXYPos());
    }
}

void SpawnManagerEnemy::attackPlayer(HealthComponent& player_health)
{
    for (const auto& enemy_instance :
         m_enemy_list |
             std::views::filter([](const auto& enemy_instance) { return Utils::IsValidUniquePtr(enemy_instance); }))
    {
        enemy_instance->initiateAttack(player_health);
    }
}

void SpawnManagerEnemy::moveEntitiesToNewPos()
{
    for (const auto& enemy_instance :
         m_enemy_list |
             std::views::filter([](const auto& enemy_instance) { return Utils::IsValidUniquePtr(enemy_instance); }))
    {
        enemy_instance->respawnEnemy();
    }
}

void SpawnManagerEnemy::checkPlayerCollision(Player& current_player, AudioManager& audio_manager)
{
    auto hovered_over_enemy =
        m_enemy_list | std::views::filter(
                           [&current_player](const std::unique_ptr<Enemy>& enemy_instance)
                           {
                               return Utils::IsValidUniquePtr(enemy_instance) &&
                                      enemy_instance->checkCollision(current_player.collision.GetCollisionPosition());
                           });

    if (!std::ranges::empty(hovered_over_enemy))
    {
        current_player.changeCursorState(Player::CursorType::enemy);

        if (auto hit_enemy = std::ranges::find_if(
                hovered_over_enemy,
                [&current_player](const std::unique_ptr<Enemy>& enemy_instance)
                { return current_player.user_input.UserAction() == UserInput::InputAction::fire; });
            hit_enemy != hovered_over_enemy.end())
        {
            current_player.score_component.increaseScore(hit_enemy->get()->score_to_give);
            hit_enemy->get()->playSound(audio_manager);
            hit_enemy->reset();
        }
    }
}

std::unique_ptr<Enemy> SpawnManagerEnemy::createEnemy(const std::pair<int, int> screen_xy)
{
    constexpr int screen_border_clamp{128};
    constexpr std::pair<int, int> base_damage_thresholds{1, 4};
    constexpr std::pair<int, int> critical_chance_thresholds{1, 10};
    constexpr std::pair<int, int> given_score_thresholds{200, 650};
    constexpr std::pair<int, int> tick_thresholds{45, 100};

    constexpr std::array<const char*, 2> ghost_sprite_paths{"assets/image/entity/enemy/ghost/ghost-1.png",
                                                            "assets/image/entity/enemy/ghost/ghost-1-inverse.png"};

    auto created_enemy = std::make_unique<Enemy>(
        std::vector<std::string>{
            ghost_sprite_paths.at(RandomGeneration::GenerateRandomNumber(0, ghost_sprite_paths.size() - 1))},
        std::array<int, 2>{
            RandomGeneration::GenerateRandomNumber(0 + screen_border_clamp, screen_xy.first - screen_border_clamp),
            RandomGeneration::GenerateRandomNumber(0 + screen_border_clamp, screen_xy.second - screen_border_clamp)},
        RandomGeneration::GenerateRandomNumber(base_damage_thresholds.first, base_damage_thresholds.second),
        RandomGeneration::GenerateRandomNumber(critical_chance_thresholds.first, critical_chance_thresholds.second),
        RandomGeneration::GenerateRandomNumber(given_score_thresholds.first, given_score_thresholds.second),
        RandomGeneration::GenerateRandomNumber(tick_thresholds.first, tick_thresholds.second));

    assert(created_enemy != nullptr);
    return created_enemy;
}

void SpawnManagerEnemy::increaseEnemyAmount(const int& current_game_score)
{
    assert(current_game_score > -1);

    constexpr std::array<int, 3> enemy_spawn_score_thresholds{135000, 320000, 480000};

    if (current_game_score > enemy_spawn_score_thresholds.at(2))
    {
        m_list_size = 4;
    }
    else if (current_game_score > enemy_spawn_score_thresholds.at(1))
    {
        m_list_size = 3;
    }
    else if (current_game_score > enemy_spawn_score_thresholds.at(0))
    {
        m_list_size = 2;
    }

    m_enemy_list.resize(m_list_size);
}
