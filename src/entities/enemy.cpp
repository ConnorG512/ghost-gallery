#include "enemy.h"
#include "../random-generation.h"

Enemy::Enemy
( 
 const int max_health, 
 const int pos_x, 
 const int pos_y, 
 const std::vector<std::string>& texture_paths, 
 const int enemy_damage 
)
  : Entity { max_health, pos_x, pos_y, texture_paths }
  , m_base_damage { enemy_damage } {}

Enemy::EntityType Enemy::getEntityType() 
{
  return Entity::EntityType::hostile;
}

int Enemy::GiveScore()
{
  return RandomGeneration::NumberBetween( 25, 50 );
}

