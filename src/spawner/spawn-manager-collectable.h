#pragma once

#include <memory>
#include <vector>

#include "../entities/collectable/coin-collectable.h"
#include "../entities/components/tick-component.h"
#include "spawn-manager.h"

class CoinCollectable;
class HeartCollectable;
class Player;
class AudioManager;

class SpawnManagerCollectable : public SpawnManager
{
  public:
    SpawnManagerCollectable(const int num_spawn_slots);
    ~SpawnManagerCollectable();

    void checkForReady();
    void drawCollectables();
    bool checkPlayerCollision(Player& current_player, AudioManager& audio_manager);

  private:
    std::vector<std::unique_ptr<Collectable>> m_collectables_list;
    std::unique_ptr<Collectable> assignCollectableToAvailableSlot();
    std::unique_ptr<CoinCollectable> createCoinCollectable();
    std::unique_ptr<HeartCollectable> createHeartCollectable();
    TickComponent m_ticker{300};

    bool isManagerFull();
    bool hasCollectableBeenInteractedWith(std::unique_ptr<Collectable>& current_collectable, Player& current_player);
};
