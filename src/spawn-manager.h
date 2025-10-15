#pragma once

#include "entities/collectable/collectable.h"

#include <vector>

class SpawnManager 
{
  public: 
    SpawnManager( int num_spawn_slots = 5);
    ~SpawnManager();

    void drawCollectables();
    void requestCollectable();

  private:
    int m_spawn_slots { 5 };
    std::vector<Collectable*> m_collectables_list; 

    Collectable* createCollectable();
    Collectable* createCoinCollectable();
    Collectable* createHeartCollectable();
    bool isManagerFull();
    void unloadManager();
};
