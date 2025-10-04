#include "entity.h"

Entity::Entity( const int pos_x, const int pos_y, const std::string& texture_path )
  : m_pos_x { pos_x }
  , m_pos_y { pos_y }
  , m_sprite { texture_path, pos_x, pos_y } {}

Entity::~Entity() {}

void Entity::drawToScreen()
{
  m_sprite.drawSprite();
}
