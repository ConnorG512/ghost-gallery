#pragma once

#include "entity.h"
#include "components/damage-component.h"
#include "components/tick-component.h"

class Player;

class Enemy : public Entity 
{
  public:
    Enemy
    ( 
      const int x_pos = 0,
      const int y_pos = 0
    );
    
    void respawnEnemy();
    void collidedWithPlayer( Player& current_player );
    void incrementAttackClock( Player& current_player );

    DamageComponent damage_component { 2, 10 };
    int score_to_give { 30 };

  private: 
    void changeEnemyGivenScore();
    void attackPlayer( Player& current_player );
    
    TickComponent m_tick_component { };
};
