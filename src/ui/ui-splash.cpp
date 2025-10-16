#include "ui-splash.h"
#include <array>
#include <raylib.h>

UiSplash::UiSplash( const int start_pos_x, const int start_pos_y, const int spacing, const int font_size )
  : Ui{ start_pos_x, start_pos_y, spacing, font_size } {}

void UiSplash::drawUi()
{
  constexpr std::array<const char*, 3> splash_titles 
  {
    "Press space to start...",
    "Press escape to exit...",
    "Current high score:",
  };

  for ( const auto* current_string : splash_titles )
  {
    DrawText( current_string, m_start_position_x, m_start_position_y, m_font_size, WHITE );
  }
}
