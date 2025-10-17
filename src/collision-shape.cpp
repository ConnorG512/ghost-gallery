#include "collision-shape.h"

#include <raylib.h>

CollisionShape::CollisionShape(const int x_pos, const int y_pos,
                               const int width, const int height)
    : m_collision_shape{(float)x_pos, (float)y_pos, (float)width, (float)height}
{
}

bool CollisionShape::isCollidingWith(const Rectangle &collider)
{
    return CheckCollisionRecs(m_collision_shape, collider);
}

void CollisionShape::updateCollisionPosition(const int pos_x, const int pos_y)
{
    m_collision_shape.x = pos_x;
    m_collision_shape.y = pos_y;
}
