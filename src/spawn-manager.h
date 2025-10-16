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

    bool isSpawnerReady();
    void drawCollectables();
    void requestCollectable();
    void checkForPlayerInteraction( Player& current_player, AudioManager& audio_manager );

  private:
    int m_spawn_slots { 5 };
    std::vector<Collectable*> m_collectables_list; 
    TickComponent m_tick_component { 180 };
    

    void allocateSlots();
    Collectable* createCollectable();
    CoinCollectable* createCoinCollectable();
    HeartCollectable* createHeartCollectable();
    bool isManagerFull();
    void unloadManager();
};
