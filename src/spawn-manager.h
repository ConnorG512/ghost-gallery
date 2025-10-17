#pragma once

#include <memory>
#include <vector>

#include "entities/collectable/collectable.h"
#include "entities/components/tick-component.h"

class CoinCollectable;
class HeartCollectable;
class Player;
class AudioManager;

class SpawnManager {
public:
  SpawnManager(int num_spawn_slots = 5);
  ~SpawnManager() = default;

  void checkForReady();
  void drawCollectables();
  void checkForPlayerInteraction(Player &current_player,
                                 AudioManager &audio_manager);

private:
  int m_spawn_slots{5};
  std::vector<std::unique_ptr<Collectable>> m_collectables_list;
  TickComponent m_tick_component{180};
  std::unique_ptr<Collectable> assignCollectableToAvailableSlot();
  std::unique_ptr<CoinCollectable> createCoinCollectable();
  std::unique_ptr<HeartCollectable> createHeartCollectable();

  bool isManagerFull();
  bool hasCollectableBeenInteractedWith(
      std::unique_ptr<Collectable> &current_collectable,
      const Player &current_player);
};
