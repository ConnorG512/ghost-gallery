#include "heart-collectable.h"
#include "entity.h"

namespace 
{
}

HeartCollectable::HeartCollectable
(
      const int pos_x, 
      const int pos_y, 
      const std::vector<std::string>& texture_paths 
) 
  : Entity{ pos_x, pos_y, texture_paths} {}

void HeartCollectable::drawToScreen()
{
  if ( is_active == true )
  {
    m_sprite.drawSprite( 0 );
  }
}

int HeartCollectable::giveHealth()
{
  return m_health_to_restore;
}
