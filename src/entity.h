#pragma once

#include "image-sprite.h"

#include <string>

class Entity 
{
  public:
    Entity( const int pos_x, const int pos_y, const std::string& texture_path );
    ~Entity();

    void drawToScreen();

  private:
    int m_pos_x { 0 };
    int m_pos_y { 0 };
    ImageSprite m_sprite;
};
