#pragma once

#include "components/damage-component.h"
#include "components/tick-component.h"
#include "entity.h"

#include <array>

class Player;

class Enemy : public Entity
{
  public:
    Enemy(const std::vector<std::string>& texture_paths,
          const std::array<int, 2> xy_pos = {0, 0},
          const int base_damage = 2,
          const int critical_chance = 0,
          const int given_score = 20,
          const int tick_threshold = 140);

    void respawnEnemy();
    void collidedWithPlayer(Player& current_player, AudioManager& audio_manager);
    [[nodiscard]] int InitiateAttack();

    void playSound(AudioManager& audio_manager);

    DamageComponent damage_component{2, 10, 2};
    int score_to_give{30};

  private:
    void changeEnemyGivenScore();

    TickComponent m_tick_component{140};
};
