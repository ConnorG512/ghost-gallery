#include "entity.h"
#include <string>
#include <vector>

Entity::Entity( const int pos_x, const int pos_y, const std::vector<std::string>& texture_paths )
  : m_pos_x { pos_x }
  , m_pos_y { pos_y }
  , m_sprite { texture_paths, pos_x, pos_y } {}

Entity::Entity( const int max_health, const int pos_x, const int pos_y, const std::vector<std::string>& texture_paths )
  : m_health { max_health }
  , m_pos_x { pos_x }
  , m_pos_y { pos_y }
  , m_sprite { texture_paths, pos_x, pos_y } {}

Entity::~Entity() {}

void Entity::drawToScreen( const int texture_index )
{
  m_sprite.drawSprite( texture_index );
}

void Entity::drawToScreen(const int texture_index, const int pos_x, const int pos_y )
{
  m_sprite.drawSprite( texture_index, pos_x, pos_y );
  m_collision.updateCollisionPosition( pos_x, pos_y );
}

bool Entity::checkCollision( const Rectangle& collider )
{
  return m_collision.isCollidingWith(collider);
}

int Entity::takeDamage( int health_to_reduce )
{
  return m_health.reduceHealth( health_to_reduce );
}

int Entity::recieveHealth( int health_to_add)
{
  return m_health.increaseHealth( health_to_add );
}

Rectangle& Entity::getCollision()
{
  return m_collision.m_collision_shape;
}

void Entity::reviveEntity()
{
  m_health.resetHealthToMax();
}
