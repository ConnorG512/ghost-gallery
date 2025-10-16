#include "entity.h"
#include "components/movement-component.h"

Entity::Entity
(
  const std::vector<std::string>& texture_paths,
  const int max_health,
  const int current_health,
  const int x_pos,
  const int y_pos
) 
  : sprite{ texture_paths, x_pos, y_pos }
  , health_component { max_health, current_health }
  , collision { x_pos, y_pos } 
  , movement_component { x_pos, y_pos } { }

bool Entity::checkCollision( const Rectangle& collider )
{
  return collision.isCollidingWith(collider);
}

void Entity::moveSprite( const int x_pos, const int y_pos )
{
  movement_component.setNewPosition( x_pos, y_pos );
  sprite.drawSprite( movement_component.x_position, movement_component.y_position );
  collision.updateCollisionPosition( movement_component.x_position, movement_component.y_position );
}
