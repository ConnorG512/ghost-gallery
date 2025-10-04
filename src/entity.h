#pragma once

#include "image-sprite.h"
#include "collision-shape.h"
#include "health-component.h"

#include <raylib.h>
#include <string>

class Entity 
{
  public:
    Entity( const int pos_x, const int pos_y, const std::string& texture_path );
    Entity( const int pos_x, const int pos_y, const std::string& texture_path, const int coll_width, const int coll_height );
    ~Entity();

    void drawToScreen();
    bool checkCollision( const Rectangle& collider );
    int takeDamage( int health_to_reduce );
    int recieveHealth( int health_to_add );

  private:
    int m_pos_x { 0 };
    int m_pos_y { 0 };
    ImageSprite m_sprite;
    CollisionShape m_collision { 0, 0, 128, 128 };
    HealthComponent m_health { 8, 8 };
};
