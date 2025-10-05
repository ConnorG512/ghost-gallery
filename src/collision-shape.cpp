#include "collision-shape.h"

#include <format>
#include <iostream>
#include <raylib.h>

CollisionShape::CollisionShape() {};

CollisionShape::CollisionShape( const int x_pos, const int y_pos, const int width, const int height )
  : m_collision_shape { (float)x_pos, (float)y_pos, (float)width, (float)height} 
{
  std::cout << std::format("{}: {},{},{},{}", "Collision shape: ", m_collision_shape.x, m_collision_shape.y, m_collision_shape.width, m_collision_shape.height ) << std::endl;
}

bool CollisionShape::isCollidingWith(const Rectangle& collider)
{
  if (CheckCollisionRecs(m_collision_shape, collider))
  {
    return true;
  }
  return false;
}

void CollisionShape::updateCollisionPosition( const int pos_x, const int pos_y )
{
  m_collision_shape.x = pos_x;
  m_collision_shape.y = pos_y;
}
