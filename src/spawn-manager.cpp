#include "spawn-manager.h"
#include "audio-manager.h"
#include "entities/collectable/coin-collectable.h"
#include "entities/collectable/heart-collectable.h"
#include "entities/player.h"
#include "random-generation.h"
#include <array>
#include <iostream>
#include <memory>

SpawnManager::SpawnManager(int num_spawn_slots) : m_spawn_slots{num_spawn_slots}
{
    m_collectables_list.resize(m_spawn_slots);
}

namespace
{
constexpr std::array<int, 2> collectable_spawn_threshold_x{200, 1400};
constexpr std::array<int, 2> collectable_spawn_threshold_y{100, 700};
} // namespace

void SpawnManager::drawCollectables()
{
    for (const auto &collectable_instance : m_collectables_list)
    {
        if (collectable_instance != nullptr)
        {
            collectable_instance->sprite.drawSprite(
                {collectable_instance->positional_component.GetXYPos()});
        }
    }
}

std::unique_ptr<Collectable> SpawnManager::assignCollectableToAvailableSlot()
{
    for (auto &collectable_instance : m_collectables_list)
    {
        if (collectable_instance == nullptr)
        {
            int random_result{RandomGeneration::NumberBetween(0, 1)};
            if (random_result == 0)
            {
                collectable_instance = createCoinCollectable();
                std::cout << "Object created at address: "
                          << collectable_instance.get() << std::endl;
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

std::unique_ptr<CoinCollectable> SpawnManager::createCoinCollectable()
{
    constexpr std::array<int, 2> coin_value_range{200, 600};

    using namespace RandomGeneration;
    return std::make_unique<CoinCollectable>(
        NumberBetween(collectable_spawn_threshold_x.at(0),
                      collectable_spawn_threshold_x.at(1)),
        NumberBetween(collectable_spawn_threshold_y.at(0),
                      collectable_spawn_threshold_y.at(1)),
        true, NumberBetween(coin_value_range.at(0), coin_value_range.at(1)));
}

std::unique_ptr<HeartCollectable> SpawnManager::createHeartCollectable()
{
    constexpr std::array<int, 2> health_restoration_range{1, 4};

    using namespace RandomGeneration;
    return std::make_unique<HeartCollectable>(
        NumberBetween(collectable_spawn_threshold_x.at(0),
                      collectable_spawn_threshold_x.at(1)),
        NumberBetween(collectable_spawn_threshold_y.at(0),
                      collectable_spawn_threshold_y.at(1)),
        true,
        NumberBetween(health_restoration_range.at(0),
                      health_restoration_range.at(1)));
}

void SpawnManager::checkForPlayerInteraction(Player &current_player,
                                             AudioManager &audio_manager)
{
    for (auto &collectable_instance : m_collectables_list)
    {
        if (collectable_instance != nullptr &&
            hasCollectableBeenInteractedWith(collectable_instance,
                                             current_player))
        {
            current_player.drawPlayerCursor(Player::CursorType::friendly);
            if (current_player.user_input.UserAction() ==
                UserInput::InputAction::fire)
            {
                collectable_instance->givePoweUp(current_player);
                collectable_instance->playSound(audio_manager);
                collectable_instance.reset();
            }
        }
    }
}

void SpawnManager::checkForReady()
{
    if (m_tick_component.IncrementAndCheckThreshold())
    {
        assignCollectableToAvailableSlot();
    }
}

bool SpawnManager::hasCollectableBeenInteractedWith(
    std::unique_ptr<Collectable> &current_collectable, Player &current_player)
{
    return current_collectable->collision.IsCollidingWith(
        current_player.collision.GetCollisionPosition());
}
