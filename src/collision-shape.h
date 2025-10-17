#pragma once

#include <raylib.h>

class CollisionShape
{
  public:
    CollisionShape(const int x_pos, const int y_pos, const int width = 128,
                   const int height = 128);

    bool isCollidingWith(const Rectangle &collider);
    void updateCollisionPosition(const int pos_x, const int pos_y);

    Rectangle m_collision_shape;
};
