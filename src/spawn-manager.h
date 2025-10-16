#pragma once

#include <vector>

#include "entities/collectable/collectable.h"
#include "entities/components/tick-component.h"

class CoinCollectable;
class HeartCollectable;
class Player;
class AudioManager;

class SpawnManager 
{
  public: 
    SpawnManager( int num_spawn_slots = 5 );
    ~SpawnManager();

    void checkForReady();
    void drawCollectables();
    void checkForPlayerInteraction( Player& current_player, AudioManager& audio_manager );

  private:
    int m_spawn_slots { 5 };
    std::vector<Collectable*> m_collectables_list; 
    TickComponent m_tick_component { 180 };
    Collectable* createCollectable();
    CoinCollectable* createCoinCollectable();
    HeartCollectable* createHeartCollectable();

    void allocateSlots();
    bool isManagerFull();
    void unloadManager();
    void spawnCollectable();
};
