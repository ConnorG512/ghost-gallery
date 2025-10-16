#pragma once

#include "entity.h"
#include "components/damage-component.h"


class Enemy : public Entity 
{
  public:
    Enemy
    ( 
      const std::vector<std::string>& texture_paths,
      const int max_health,
      const int current_health,
      const int x_pos,
      const int y_pos,
      const int score_to_give = 30
    );


  protected:
    const int m_score_to_give { 30 };
};
