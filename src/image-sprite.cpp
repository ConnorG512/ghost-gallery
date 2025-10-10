#include "image-sprite.h"

#include <raylib.h>
#include <string>
#include <vector>

ImageSprite::ImageSprite( 
    const std::vector<std::string>& texture_path_strings, 
    const int x_pos, 
    const int y_pos 
)
  : m_pos_x { x_pos }
  , m_pos_y { y_pos } 
{
  loadTextures( texture_path_strings );
}

ImageSprite::~ImageSprite() 
{
  for (int i = 0; i < m_loaded_textures.size(); i++ )
  {
    UnloadTexture(m_loaded_textures.at( i ));
  }
}

void ImageSprite::drawSprite( const int texture_index ) 
{
  DrawTexture( m_loaded_textures.at( texture_index ), m_pos_x, m_pos_y, WHITE );
}

void ImageSprite::drawSprite( const int texture_index, const int x_pos, const int y_pos ) 
{
  m_pos_x = x_pos;
  m_pos_y = y_pos;

  DrawTexture( m_loaded_textures.at( texture_index ), m_pos_x, m_pos_y, WHITE );
}

void ImageSprite::loadTextures( const std::vector<std::string>& texture_samples ) 
{
  for (const auto texture_path : texture_samples )
  {
    m_loaded_textures.push_back(LoadTexture(texture_path.c_str()));
  }
}
