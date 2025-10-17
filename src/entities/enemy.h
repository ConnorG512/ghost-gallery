#pragma once

#include "components/damage-component.h"
#include "components/tick-component.h"
#include "entity.h"

class Player;

class Enemy : public Entity {
public:
  Enemy(const int x_pos = 0, const int y_pos = 0);

  void respawnEnemy();
  void collidedWithPlayer(Player &current_player, AudioManager &audio_manager);
  int InitiateAttack();

  void playSound(AudioManager &audio_manager);

  DamageComponent damage_component{2, 10};
  int score_to_give{30};

private:
  void changeEnemyGivenScore();

  TickComponent m_tick_component{};
};
