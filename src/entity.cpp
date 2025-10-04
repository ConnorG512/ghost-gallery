#include "entity.h"

Entity::Entity( const int pos_x, const int pos_y, const std::string& texture_path )
  : m_pos_x { pos_x }
  , m_pos_y { pos_y }
  , m_sprite { texture_path, pos_x, pos_y } {}

Entity::Entity( const int pos_x, const int pos_y, const std::string& texture_path, const float coll_width, const float coll_height );
  : m_pos_x { pos_x }
  , m_pos_y { pos_y }
  , m_sprite { texture_path, pos_x, pos_y }
  , m_collision { (float)pos_x, (float)pos_y, coll_width, coll_height } {}

Entity::~Entity() {}

void Entity::drawToScreen()
{
  m_sprite.drawSprite();
}
bool Entity::checkCollision( const Rectangle& collider )
{
  return m_collision.isCollidingWith(collider);
}
