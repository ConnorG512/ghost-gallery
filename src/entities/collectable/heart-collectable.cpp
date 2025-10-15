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
      const bool is_hidden,
      const std::vector<std::string>& texture_paths 
) 
  : Entity{ pos_x, pos_y, is_hidden, texture_paths} {}

int HeartCollectable::giveHealth()
{
  if ( !m_is_hidden  )
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
  setHidden( false );
  changePosition();
}

HeartCollectable::EntityType HeartCollectable::getEntityType() 
{
  return HeartCollectable::EntityType::friendly;
}
