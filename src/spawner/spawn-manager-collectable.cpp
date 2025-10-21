#include "spawn-manager-collectable.h"
#include "../audio-manager.h"
#include "../entities/collectable/coin-collectable.h"
#include "../entities/collectable/heart-collectable.h"
#include "../entities/player.h"
#include "../util/random-generation.h"
#include "../util/utils.h"
#include "spawn-manager.h"

#include <algorithm>
#include <array>
#include <memory>
#include <ranges>

SpawnManagerCollectable::SpawnManagerCollectable(const int num_spawn_slots) : SpawnManager{num_spawn_slots}
{
    m_collectables_list.resize(m_num_available_slots);
}

namespace
{
constexpr std::array<int, 2> collectable_spawn_threshold_x{200, 1400};
constexpr std::array<int, 2> collectable_spawn_threshold_y{100, 700};
} // namespace

void SpawnManagerCollectable::drawCollectables()
{
    for (const auto& collectable_instance : m_collectables_list)
    {
        if (collectable_instance != nullptr)
        {
            collectable_instance->sprite.drawSprite({collectable_instance->positional_component.GetXYPos()});
        }
    }
}

std::unique_ptr<Collectable> SpawnManagerCollectable::assignCollectableToAvailableSlot()
{
    for (auto& collectable_instance : m_collectables_list)
    {
        if (collectable_instance == nullptr)
        {
            int random_result{RandomGeneration::GenerateRandomNumber(0, 1)};
            if (random_result == 0)
            {
                collectable_instance = createCoinCollectable();
                break;
            }
            else
            {
                collectable_instance = createHeartCollectable();
                break;
            }
        }
    }
    return nullptr;
}

std::unique_ptr<CoinCollectable> SpawnManagerCollectable::createCoinCollectable()
{
    constexpr std::array<int, 2> coin_value_range{200, 600};

    using namespace RandomGeneration;
    return std::make_unique<CoinCollectable>(
        GenerateRandomNumber(collectable_spawn_threshold_x.at(0), collectable_spawn_threshold_x.at(1)),
        GenerateRandomNumber(collectable_spawn_threshold_y.at(0), collectable_spawn_threshold_y.at(1)),
        true,
        GenerateRandomNumber(coin_value_range.at(0), coin_value_range.at(1)));
}

std::unique_ptr<HeartCollectable> SpawnManagerCollectable::createHeartCollectable()
{
    constexpr std::array<int, 2> health_restoration_range{1, 4};

    using namespace RandomGeneration;
    return std::make_unique<HeartCollectable>(
        GenerateRandomNumber(collectable_spawn_threshold_x.at(0), collectable_spawn_threshold_x.at(1)),
        GenerateRandomNumber(collectable_spawn_threshold_y.at(0), collectable_spawn_threshold_y.at(1)),
        true,
        GenerateRandomNumber(health_restoration_range.at(0), health_restoration_range.at(1)));
}

bool SpawnManagerCollectable::checkPlayerCollision(Player& current_player, AudioManager& audio_manager)
{
    bool has_player_collided{false};

    std::ranges::for_each(
        m_collectables_list |
            std::views::filter([](std::unique_ptr<Collectable>& collectable_instance)
                               { return Utils::IsValidUniquePtr(collectable_instance); }) |
            std::views::filter(
                [&current_player](std::unique_ptr<Collectable>& collectable_instance)
                { return collectable_instance->checkCollision(current_player.collision.GetCollisionPosition()); }),
        [&](std::unique_ptr<Collectable>& collectable_instance)
        {
            has_player_collided = true;
            if (current_player.user_input.UserAction() == UserInput::InputAction::fire)
            {
                collectable_instance->givePoweUp(current_player);
                collectable_instance->playSound(audio_manager);
                collectable_instance.reset();
            }
        });

    return has_player_collided;
}

void SpawnManagerCollectable::checkForReady()
{
    if (m_ticker.IncrementAndCheckThreshold())
    {
        assignCollectableToAvailableSlot();
    }
}

bool SpawnManagerCollectable::hasCollectableBeenInteractedWith(std::unique_ptr<Collectable>& current_collectable,
                                                               Player& current_player)
{
    return current_collectable->collision.IsCollidingWith(current_player.collision.GetCollisionPosition());
}
