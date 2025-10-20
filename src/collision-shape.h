#pragma once

#include <array>
#include <raylib.h>

class CollisionShape
{
  public:
    CollisionShape(const std::array<int, 2> xy_pos = {0, 0}, const int width = 128, const int height = 128);

    bool IsCollidingWith(const Rectangle& collider);
    void updateCollisionPosition(const std::array<int, 2>& xy_pos = {0, 0});
    Rectangle& GetCollisionPosition();

  private:
    Rectangle m_collision_shape;
};
