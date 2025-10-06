#include "entity.h"
#include <string>

Entity::Entity( const int pos_x, const int pos_y, const std::string& texture_path )
  : m_pos_x { pos_x }
  , m_pos_y { pos_y }
  , m_sprite { texture_path, pos_x, pos_y } {}

Entity::Entity( const int pos_x, const int pos_y, const std::string& texture_path, const int coll_width, const int coll_height )
  : m_pos_x { pos_x }
  , m_pos_y { pos_y }
  , m_sprite { texture_path, pos_x, pos_y }
  , m_collision { pos_x, pos_y, coll_width, coll_height } {}

Entity::Entity( const int pos_x, const int pos_y, const std::string& texture_path, const std::string& texture_path_2, const int coll_width, const int coll_height )
  : m_pos_x { pos_x }
  , m_pos_y { pos_y }
  , m_sprite { texture_path, texture_path_2, pos_x, pos_y }
  , m_collision { pos_x, pos_y, coll_width, coll_height } {}

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
