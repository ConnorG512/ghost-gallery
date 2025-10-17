#include "ui-gameplay.h"
#include <array>
#include <raylib.h>

UiGameplay::UiGameplay( const int start_pos_x, const int start_pos_y, const int spacing, const int font_size )
  : Ui { start_pos_x, start_pos_y, spacing, font_size } {}

void UiGameplay::drawUi( const std::array<int, 3>& player_stats )
{

  constexpr std::array<const char*, 3> ui_strings 
  {
    "Score",
    "Health",
    "Multiplier",
  };
  
  int text_start_pos_y { m_start_position_y };
  for ( auto* current_string : ui_strings )
  {
    DrawText( current_string, m_start_position_x, text_start_pos_y, m_font_size, WHITE );
    text_start_pos_y += m_spacing;
  }
}
