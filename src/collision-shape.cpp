#include "collision-shape.h"

#include <raylib.h>

CollisionShape::CollisionShape(const std::array<int, 2> xy_pos, const int width, const int height)
    : m_collision_shape((float)xy_pos.at(0), (float)xy_pos.at(1), (float)width, (float)height)
{
}

bool CollisionShape::IsCollidingWith(const Rectangle& collider)
{
    return CheckCollisionRecs(m_collision_shape, collider);
}

void CollisionShape::updateCollisionPosition(const std::array<int, 2>& xy_pos)
{
    m_collision_shape.x = xy_pos.at(0);
    m_collision_shape.y = xy_pos.at(1);
}

const Rectangle& CollisionShape::GetCollisionPosition() { return m_collision_shape; }
