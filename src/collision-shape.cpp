#include "collision-shape.h"

#include <iostream>
#include <raylib.h>

CollisionShape::CollisionShape() {};

CollisionShape::CollisionShape( const int x_pos, const int y_pos, const int width, const int height )
  : m_collision_shape { (float)x_pos, (float)y_pos, (float)width, (float)height} {}

bool CollisionShape::isCollidingWith(const Rectangle& collider)
{
  if (CheckCollisionRecs(m_collision_shape, collider))
  {
    std::cout << "Collision hit!" << std::endl;
    return true;
  }
  return false;
}
