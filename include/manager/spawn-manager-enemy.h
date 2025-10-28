#pragma once

#include "entity/enemy.h"
#include "manager/spawn-manager.h"

#include <memory>
#include <vector>

class HealthComponent;
class Player;

class SpawnManagerEnemy : public SpawnManager
{
  public:
    SpawnManagerEnemy(const int num_spawn_slots);

    void requestEnemySpawn(const int& current_game_score, const std::pair<int, int> screen_xy);
    void drawEnemySprites();
    void attackPlayer(Player& current_player, AudioManager& audio_manager);
    void moveEntitiesToNewPos();
    void checkPlayerCollision(Player& current_player, AudioManager& audio_manager);
    void increaseEnemyAmount(const int& current_game_score);

  protected:
    std::vector<std::unique_ptr<Enemy>> m_enemy_list;
    std::unique_ptr<Enemy> createEnemy(const std::pair<int, int> screen_xy);
};
