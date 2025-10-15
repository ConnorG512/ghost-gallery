#pragma once

#include <vector>

#include "entities/collectable/collectable.h"

class CoinCollectable;
class HeartCollectable;

class SpawnManager 
{
  public: 
    SpawnManager( int num_spawn_slots = 5 );
    ~SpawnManager();

    void drawCollectables();
    void requestCollectable();

  private:
    int m_spawn_slots { 5 };
    std::vector<Collectable*> m_collectables_list; 

    Collectable* createCollectable();
    CoinCollectable* createCoinCollectable();
    HeartCollectable* createHeartCollectable();
    bool isManagerFull();
    void unloadManager();
};
