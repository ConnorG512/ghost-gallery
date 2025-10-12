#pragma once

#include "entity.h"
#include "../damage-component.h"

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
    
    DamageComponent damage_component { 1, 10, 1 };
    
  protected:
    int m_base_damage{ 1 };

};
