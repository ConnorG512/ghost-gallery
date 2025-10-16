#include "game-ui.h"
#include "text-render.h"

#include <array>
#include <format>
#include <raylib.h>

GameUi::GameUi( const int starting_pos_x, const int starting_pos_y, const int font_size, const int text_spacing )
  :  m_starting_pos_x { starting_pos_x }
  ,  m_starting_pos_y { starting_pos_y }
  ,  m_font_size { font_size }
  ,  m_text_spacing { text_spacing } {}

void GameUi::drawAll( const std::array<int, 3>& game_props )
{
  constexpr std::array<const char *, 3> ui_names { "Score", "Health", "Multiplier" };
  TextRender::drawTextToScreen(std::format("{}: {}", ui_names.at( 0 ), game_props.at( 0 )), m_starting_pos_x, m_starting_pos_y );
  TextRender::drawTextToScreen(std::format("{}: {}", ui_names.at( 1 ), game_props.at( 1 )), m_starting_pos_x, m_starting_pos_y + 30);
  TextRender::drawTextToScreen(std::format("{}: {}", ui_names.at( 2 ), game_props.at( 2 )), m_starting_pos_x, m_starting_pos_y + 60);
}

