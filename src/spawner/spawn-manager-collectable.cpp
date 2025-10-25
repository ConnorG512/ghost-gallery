#include "spawn-manager-collectable.h"
#include "../audio-manager.h"
#include "../entities/collectable/candy-collectable.h"
#include "../entities/collectable/coin-collectable.h"
#include "../entities/collectable/heart-collectable.h"
#include "../entities/player.h"
#include "../util/random-generation.h"
#include "../util/utils.h"
#include "spawn-manager.h"

#include <algorithm>
#include <array>
#include <cassert>
#include <memory>
#include <ranges>
#include <utility>

namespace
{
constexpr int entity_screen_clamp{128};

} // namespace

SpawnManagerCollectable::SpawnManagerCollectable(const int num_spawn_slots) : SpawnManager{num_spawn_slots}
{
    m_collectables_list.resize(m_num_available_slots);
}

SpawnManagerCollectable::~SpawnManagerCollectable() { m_collectables_list.clear(); }

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

std::unique_ptr<Collectable>
SpawnManagerCollectable::assignCollectableToAvailableSlot(const std::pair<int, int> screen_xy)
{
    for (auto& collectable_instance :
         m_collectables_list | std::views::filter([this](const std::unique_ptr<Collectable>& collectable_instance)
                                                  { return !Utils::IsValidUniquePtr(collectable_instance); }))
    {
        enum class CollectableId
        {
            coin,
            heart,
            candy,
            end,
        };

        const CollectableId chosen_item = []()
        {
            const int result{RandomGeneration::GenerateRandomNumber(0, std::to_underlying(CollectableId::end) - 1)};
            assert(result < std::to_underlying(CollectableId::end));
            return static_cast<CollectableId>(result);
        }();

        switch (chosen_item)
        {
            case CollectableId::coin:
                collectable_instance = createCoinCollectable(screen_xy);
                break;
            case CollectableId::heart:
                collectable_instance = createHeartCollectable(screen_xy);
                break;
            case CollectableId::candy:
                collectable_instance = createCandyCollectable(screen_xy);
                break;
            default:
                break;
        }
    }
    return nullptr;
}

std::unique_ptr<CoinCollectable> SpawnManagerCollectable::createCoinCollectable(const std::pair<int, int> screen_xy)
{
    constexpr std::array<int, 2> coin_value_range{200, 600};

    using namespace RandomGeneration;
    auto created_collectable = std::make_unique<CoinCollectable>(
        GenerateRandomNumber(0 + entity_screen_clamp, screen_xy.first - entity_screen_clamp),
        GenerateRandomNumber(0 + entity_screen_clamp, screen_xy.second - entity_screen_clamp),
        GenerateRandomNumber(coin_value_range.at(0), coin_value_range.at(1)));

    assert(created_collectable != nullptr);
    return created_collectable;
}

std::unique_ptr<HeartCollectable> SpawnManagerCollectable::createHeartCollectable(const std::pair<int, int> screen_xy)
{
    constexpr std::array<int, 2> health_restoration_range{1, 4};

    using namespace RandomGeneration;
    auto created_collectable = std::make_unique<HeartCollectable>(
        GenerateRandomNumber(0 + entity_screen_clamp, screen_xy.first - entity_screen_clamp),
        GenerateRandomNumber(0 + entity_screen_clamp, screen_xy.second - entity_screen_clamp),
        GenerateRandomNumber(health_restoration_range.at(0), health_restoration_range.at(1)));

    assert(created_collectable != nullptr);
    return created_collectable;
}

std::unique_ptr<CandyCollectable> SpawnManagerCollectable::createCandyCollectable(const std::pair<int, int> screen_xy)
{
    constexpr std::array<int, 2> candy_multiplier_value_range{1, 5};

    using namespace RandomGeneration;
    auto created_collectable = std::make_unique<CandyCollectable>(
        GenerateRandomNumber(0 + entity_screen_clamp, screen_xy.first - entity_screen_clamp),
        GenerateRandomNumber(0 + entity_screen_clamp, screen_xy.second - entity_screen_clamp),
        GenerateRandomNumber(candy_multiplier_value_range.at(0), candy_multiplier_value_range.at(1)));

    assert(created_collectable != nullptr);
    return created_collectable;
}

bool SpawnManagerCollectable::checkPlayerCollision(Player& current_player, AudioManager& audio_manager)
{
    auto const valid_collectable = std::ranges::find_if(
        m_collectables_list,
        [&current_player](const std::unique_ptr<Collectable>& collectable_instance)
        {
            return Utils::IsValidUniquePtr(collectable_instance) &&
                   collectable_instance->checkCollision(current_player.collision.GetCollisionPosition());
        });

    if (valid_collectable != m_collectables_list.end() &&
        current_player.user_input.UserAction() == UserInput::InputAction::fire)
    {
        valid_collectable->get()->givePowerUp(current_player);
        valid_collectable->get()->playSound(audio_manager);
        valid_collectable->reset();
        return true;
    }
    return false;
}

void SpawnManagerCollectable::checkForReady(const std::pair<int, int> screen_xy)
{
    if (m_ticker.IncrementAndCheckThreshold())
    {
        assignCollectableToAvailableSlot(screen_xy);
    }
}

bool SpawnManagerCollectable::hasCollectableBeenInteractedWith(std::unique_ptr<Collectable>& current_collectable,
                                                               Player& current_player)
{
    return current_collectable->collision.IsCollidingWith(current_player.collision.GetCollisionPosition());
}
