#include "image-sprite.h"
#include <raylib.h>

ImageSprite::ImageSprite( const std::string& file_path, const int x_pos, const int y_pos )
  : m_pos_x { x_pos }
  , m_pos_y { y_pos } 
  , m_current_texture { LoadTexture( file_path.c_str() )} {}

ImageSprite::~ImageSprite() 
{
  UnloadTexture(m_current_texture);
}

void ImageSprite::drawSprite() 
{
  DrawTexture( m_current_texture, m_pos_x, m_pos_y, WHITE );
}

void ImageSprite::drawSprite( const int x_pos, const int y_pos ) 
{
  m_pos_x = x_pos;
  m_pos_y = y_pos;

  DrawTexture( m_current_texture, m_pos_x, m_pos_y, WHITE );
}
