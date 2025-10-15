#include "movement-component.h"

MovementComponent::MovementComponent( int x_pos, int y_pos )
  : x_position { x_pos }
  , y_position { y_pos } {}

void MovementComponent::setNewPosition( int x_pos, int y_pos )
{
  x_position = x_pos;
  y_position = y_pos;
}

void MovementComponent::moveXPosition( int x_pos )
{
  x_position = x_pos;
}

void MovementComponent::moveYPosition( int x_pos )
{
  y_position = x_pos;
}
