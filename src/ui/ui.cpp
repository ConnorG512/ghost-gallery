#include "ui.h"
#include <raylib.h>

Ui::Ui( const int start_pos_x, const int start_pos_y, const int spacing, const int font_size )
  : m_start_position_x { start_pos_x }, m_start_position_y { start_pos_y }, m_spacing { spacing } {}

void Ui::drawui()
{
  constexpr const char* dummy_text { "Dummy Text" };
  DrawText(dummy_text, m_start_position_x, m_start_position_y, m_font_size, WHITE );
}
