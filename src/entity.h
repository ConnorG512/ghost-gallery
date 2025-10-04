#pragma once

#include "image-sprite.h"
#include "collision-shape.h"

#include <raylib.h>
#include <string>

class Entity 
{
  public:
    Entity( const int pos_x, const int pos_y, const std::string& texture_path );
    Entity( const int pos_x, const int pos_y, const std::string& texture_path, const float coll_width, const float coll_height );
    ~Entity();

    void drawToScreen();
    bool checkCollision( const Rectangle& collider );

  private:
    int m_pos_x { 0 };
    int m_pos_y { 0 };
    ImageSprite m_sprite;
    CollisionShape m_collision { 0, 0, 128, 128 };
};
