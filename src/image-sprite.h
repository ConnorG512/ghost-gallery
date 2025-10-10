#pragma once

#include <array>
#include <raylib.h>
#include <string>
#include <vector>

class ImageSprite 
{
  public:
    ImageSprite( const std::vector<std::string>& texture_path_strings, const int x_pos, const int y_pos );
    ~ImageSprite();

    void drawSprite( const int texture_index );
    void drawSprite( const int texture_index, const int x_pos, const int y_pos ); 
    
  private:
    int m_pos_x { 0 };
    int m_pos_y { 0 };
    std::vector<Texture2D> m_loaded_textures {};
    
    void loadTextures( const std::vector<std::string>& texture_samples );
};
