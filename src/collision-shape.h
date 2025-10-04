#pragma once

#include <raylib.h>

class CollisionShape 
{
  public:
    CollisionShape();
    CollisionShape( const int x_pos, const int y_pos, const int width, const int height );
    bool isCollidingWith(const Rectangle& collider);

  private:
    Rectangle m_collision_shape;
};
