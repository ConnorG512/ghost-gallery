#pragma once

#include "components/health-component.h"
#include "entity.h"
#include "components/damage-component.h"
#include "components/score-component.h"

class Window;
class ScoreComponent;

class Player : public Entity
{
  public:
    Player
    (
      const int x_pos = 0,
      const int y_pos = 0
    );
    ScoreComponent score_component { };

    void ResetPlayerStats();
    
    enum class CursorType
    {
      neutral = 0,
      enemy = 1,
      friendly = 2,
    };
  
  protected: 

};
