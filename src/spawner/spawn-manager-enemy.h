#pragma once

#include "../entities/enemy.h"
#include "spawn-manager.h"

#include <memory>
#include <vector>

class HealthComponent;
class Player;

class SpawnManagerEnemy : public SpawnManager
{
  public:
    SpawnManagerEnemy(const int num_spawn_slots);

    void requestEnemySpawn(const int& current_game_score);
    void drawEnemySprites();
    void attackPlayer(HealthComponent& player_health);
    void moveEntitiesToNewPos();
    void scanForPlayerCollision(Player& current_player);

  protected:
    std::vector<std::unique_ptr<Enemy>> m_enemy_list;
    std::unique_ptr<Enemy> createEnemy();
};
