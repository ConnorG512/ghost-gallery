#include "text-render.h"
#include <format>
#include <raylib.h>
#include <string>

namespace 
{
  constexpr int default_font_size { 32 };
}

void TextRender::drawTextToScreen(const std::string& displayed_text, const int pos_x, const int pos_y, const int size)
{
  DrawText(displayed_text.c_str(), pos_x, pos_y, size, WHITE);
}

void TextRender::drawTextToScreen(const std::string& displayed_text, const int pos_x, const int pos_y )
{
  DrawText(displayed_text.c_str(), pos_x, pos_y, default_font_size, WHITE);
}

void TextRender::drawGameUi( const std::string& displayed_text, const int value, const int y_pos )
{
  drawTextToScreen
  ( 
    std::format("{}: {}", displayed_text, std::to_string( value )), 
    10, 
    y_pos 
  );
}
