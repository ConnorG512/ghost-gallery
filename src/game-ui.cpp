#include "game-ui.h"

#include <raylib.h>

GameUi::GameUi( int starting_pos_x, int starting_pos_y, int font_size, int text_spacing )
  :  m_starting_pos_x { starting_pos_x }
  ,  m_starting_pos_y { starting_pos_y }
  ,  m_font_size { font_size }
  ,  m_text_spacing { text_spacing } {}

void GameUi::drawAll()
{
}

