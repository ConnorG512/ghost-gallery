#pragma once

#include <raylib.h>
#include <string>
#include <vector>

class ImageSprite 
{
  public:
    ImageSprite( const std::string& file_path, const int x_pos, const int y_pos );
    ~ImageSprite();

    void drawSprite();
    void drawSprite( const int x_pos, const int y_pos ); 

  private:
    int m_pos_x { 0 };
    int m_pos_y { 0 };
    Texture2D m_current_texture { };
};
