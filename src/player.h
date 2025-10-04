#pragma once

#include "entity.h"
#include "health-component.h"

#include <raylib.h>

class Player : public Entity
{
  public:
    int addToScore(int score_to_add);

    int m_current_score { 0 };
  private:
    HealthComponent m_player_health { 8, 8 };
};
