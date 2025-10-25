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

    void requestEnemySpawn(const int& current_game_score, const std::pair<int, int> screen_xy);
    void drawEnemySprites();
    void attackPlayer(HealthComponent& player_health);
    void moveEntitiesToNewPos();
    [[nodiscard]] bool checkPlayerCollision(Player& current_player, AudioManager& audio_manager);
    void increaseEnemyAmount(const int& current_game_score);

  protected:
    int m_list_size{1};
    std::vector<std::unique_ptr<Enemy>> m_enemy_list;
    std::unique_ptr<Enemy> createEnemy(const std::pair<int, int> screen_xy);
};
