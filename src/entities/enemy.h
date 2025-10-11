#pragma once

#include "entity.h"

class ScoreManager;

class Enemy : public Entity 
{
  public:
    Enemy
    ( 
      const int max_health, 
      const int pos_x, 
      const int pos_y, 
      const std::vector<std::string>& texture_paths, 
      const int enemy_damage 
    );
    
    int dealDamage( ScoreManager& score_manager );

  protected:
    int m_current_damage { 1 };

};
