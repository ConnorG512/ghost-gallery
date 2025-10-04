#include "entity.h"
#include <memory>

Entity::Entity( const int pos_x, const int pos_y, const std::string& texture_path )
  : m_pos_x { pos_x }
  , m_pos_y { pos_y }
  , m_sprite { texture_path, pos_x, pos_y } {}

Entity::Entity( const int pos_x, const int pos_y, const std::string& texture_path, const int coll_width, const int coll_height )
  : m_pos_x { pos_x }
  , m_pos_y { pos_y }
  , m_sprite { texture_path, pos_x, pos_y }
  , m_collision { pos_x, pos_y, coll_width, coll_height } {}

Entity::~Entity() {}

void Entity::drawToScreen()
{
  m_sprite.drawSprite();
}

void Entity::drawToScreen( const int pos_x, const int pos_y )
{
  m_sprite.drawSprite( pos_x, pos_y );
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
