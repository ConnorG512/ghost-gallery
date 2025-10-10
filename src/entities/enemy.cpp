#include "enemy.h"

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

int Enemy::dealDamage()
{
  return m_current_damage;
}
