#pragma once

#include "../entities/enemy.h"
#include "spawn-manager.h"

#include <memory>
#include <vector>

class SpawnManagerEnemy : public SpawnManager
{
  public:
    SpawnManagerEnemy(const int tick_threshold, const int num_spawn_slots);

    void requestEnemySpawn();

  protected:
    std::vector<std::unique_ptr<Enemy>> m_enemy_list;
    std::unique_ptr<Enemy> createEnemy();
};
