#include "heart-collectable.h"
#include "entity.h"
#include "../random-generation.h"

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
void HeartCollectable::drawToScreen( int x_pos, int y_pos )
{
  m_sprite.drawSprite( 0, x_pos, y_pos );
}

int HeartCollectable::giveHealth()
{
  if (is_active == true )
  {
    return m_health_to_restore;
  }
  return 0;
}

void HeartCollectable::changePosition()
{
  drawToScreen
  (
    RandomGeneration::NumberBetween( 300, 1400),
    RandomGeneration::NumberBetween( 200, 700));
}
