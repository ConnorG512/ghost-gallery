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
  if ( m_is_active == true )
  {
    m_sprite.drawSprite( 0 );
  }
}
void HeartCollectable::drawToScreen( int x_pos, int y_pos )
{
  if ( m_is_active == true )
  {
    m_sprite.drawSprite( 0, x_pos, y_pos );
  }
}

int HeartCollectable::giveHealth()
{
  if ( m_is_active == true )
  {
    return m_health_to_restore;
  }
  return 0;
}

void HeartCollectable::changePosition()
{
  m_pos_x = RandomGeneration::NumberBetween( 300, 1400);
  m_pos_y = RandomGeneration::NumberBetween( 200, 700);
}

void HeartCollectable::moveAndActivateToNewLocation()
{
  m_is_active = true;
  changePosition();
}

bool HeartCollectable::isHeartActive()
{
  return m_is_active;
}
    
void HeartCollectable::deactivatePickup()
{
  m_is_active = false;
}
