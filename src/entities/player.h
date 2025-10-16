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
      const std::vector<std::string>& texture_paths,
      const int max_health,
      const int current_health,
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
