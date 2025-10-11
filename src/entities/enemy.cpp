#include "enemy.h"
#include "../score-manager.h"
#include <array>

Enemy::Enemy
( 
 const int max_health, 
 const int pos_x, 
 const int pos_y, 
 const std::vector<std::string>& texture_paths, 
 const int enemy_damage 
)
  : Entity { max_health, pos_x, pos_y, texture_paths }
  , m_current_damage { enemy_damage } {}

int Enemy::dealDamage( ScoreManager& score_manager )
{
  constexpr std::array<int, 3> damage_multiplier { 1, 2, 4 };

  if ( score_manager.m_current_score > 400 )
  {
    return m_current_damage * damage_multiplier[ 1 ];
  }
  else if ( score_manager.m_current_score > 800 )
  {
    return m_current_damage * damage_multiplier[ 2 ];
  }
  else {
    return m_current_damage * damage_multiplier [ 0 ];
  }
}
