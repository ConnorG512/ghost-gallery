#pragma once

#include "health-component.h"

class Player 
{
  public:
    Player();
    Player(int max_health, int current_health );
    ~Player();

    int addToScore(int score_to_add);
    int reduceLives(int num_to_reduce);
    int takeDamage( int health_to_reduce );
    int recieveHealth( int health_to_add);

    int m_current_score { 0 };

  private:
    HealthComponent m_player_health { 8, 8 };
};
