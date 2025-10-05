#pragma once

#include <raylib.h>

struct CollisionShape 
{
    CollisionShape();
    CollisionShape( const int x_pos, const int y_pos, const int width, const int height );
    
    bool isCollidingWith(const Rectangle& collider);
    void updateCollisionPosition( const int pos_x, const int pos_y );

    Rectangle m_collision_shape;
};
