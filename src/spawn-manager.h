#pragma once

#include <vector>

#include "entities/collectable/collectable.h"

class CoinCollectable;
class HeartCollectable;
class Player;

class SpawnManager 
{
  public: 
    SpawnManager( int num_spawn_slots = 5 );
    ~SpawnManager();

    void drawCollectables();
    void requestCollectable();
    void checkForPlayerCollision( Player& current_player );

  private:
    int m_spawn_slots { 5 };
    std::vector<Collectable*> m_collectables_list; 

    Collectable* createCollectable();
    CoinCollectable* createCoinCollectable();
    HeartCollectable* createHeartCollectable();
    bool isManagerFull();
    void unloadManager();
};
