#include "entity.h"
#include <string>
#include <vector>

Entity::Entity( const int pos_x, const int pos_y, const std::vector<std::string>& texture_paths )
  : m_pos_x { pos_x }
  , m_pos_y { pos_y }
  , m_sprite { texture_paths, pos_x, pos_y } {}

Entity::Entity( const int pos_x, const int pos_y, const bool is_hidden, const std::vector<std::string>& texture_paths )
  : m_pos_x { pos_x }
  , m_pos_y { pos_y }
  , m_is_hidden { is_hidden }
  , m_sprite { texture_paths, pos_x, pos_y } {}

Entity::Entity( const int max_health, const int pos_x, const int pos_y, const std::vector<std::string>& texture_paths )
  : health_component { max_health }
  , m_pos_x { pos_x }
  , m_pos_y { pos_y }
  , m_sprite { texture_paths, pos_x, pos_y } {}

Entity::~Entity() = default;

void Entity::drawToScreen( const int texture_index )
{
  if ( !m_is_hidden )
  {
    m_sprite.drawSprite( texture_index );
  }
}

void Entity::drawToScreen( const int texture_index, const int pos_x, const int pos_y )
{
  if ( !m_is_hidden )
  {
    m_sprite.drawSprite( texture_index, pos_x, pos_y );
    m_collision.updateCollisionPosition( pos_x, pos_y );
  }
}

bool Entity::checkCollision( const Rectangle& collider )
{
  return m_collision.isCollidingWith(collider);
}

Rectangle& Entity::getCollision()
{
  return m_collision.m_collision_shape;
}

void Entity::setHidden(bool is_hidden )
{
  m_is_hidden = is_hidden;
}

bool Entity::isHidden()
{
  return m_is_hidden;
}

Entity::EntityType Entity::getEntityType()
{
  return EntityType::neutral;
}
