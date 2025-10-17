#include "ui.h"
#include <raylib.h>

Ui::Ui(const int start_pos_x, const int start_pos_y, const int spacing,
       const int font_size)
    : m_start_position_x{start_pos_x}, m_start_position_y{start_pos_y},
      m_spacing{spacing}, m_font_size{font_size}
{
}
