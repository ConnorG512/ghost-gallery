#include "image-sprite.h"
#include <raylib.h>

ImageSprite::ImageSprite( const std::string& file_path, const int x_pos, const int y_pos )
  : m_pos_x { x_pos }
  , m_pos_y { y_pos } 
  , m_loaded_textures { LoadTexture( file_path.c_str())} {}

ImageSprite::ImageSprite( const std::string& file_path, const std::string& file_path_2, const int x_pos, const int y_pos )
  : m_pos_x { x_pos }
  , m_pos_y { y_pos } 
  , m_loaded_textures { LoadTexture( file_path.c_str()), LoadTexture( file_path_2.c_str())} {}

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

