#pragma once

#include "entity/coin-collectable.h"
#include "component/tick-component.h"
#include "manager/spawn-manager.h"

#include <memory>
#include <vector>

class CoinCollectable;
class HeartCollectable;
class CandyCollectable;
class Player;
class AudioManager;

class SpawnManagerCollectable : public SpawnManager
{
  public:
    SpawnManagerCollectable(const int num_spawn_slots);
    ~SpawnManagerCollectable();

    void checkForReady(const std::pair<int, int> screen_xy);
    void drawCollectables();
    void checkPlayerCollision(Player& current_player, AudioManager& audio_manager);

  private:
    TickComponent m_ticker{300};
    std::vector<std::unique_ptr<Collectable>> m_collectables_list;

    std::unique_ptr<Collectable> assignCollectableToAvailableSlot(const std::pair<int, int> screen_xy);
    [[nodiscard]] std::unique_ptr<CoinCollectable> createCoinCollectable(const std::pair<int, int> screen_xy);
    [[nodiscard]] std::unique_ptr<HeartCollectable> createHeartCollectable(const std::pair<int, int> screen_xy);
    [[nodiscard]] std::unique_ptr<CandyCollectable> createCandyCollectable(const std::pair<int, int> screen_xy);
    bool isManagerFull();
};
