#pragma once

#include <string>
#include <raylib.h>

namespace TextRender 
{
  void drawTextToScreen(const std::string& displayed_text, const int pos_x, const int pos_y, const int size );
  void drawTextToScreen(const std::string& displayed_text, const int pos_x, const int pos_y );
  void drawTextToScreen(const std::string& displayed_text );
  void drawGameUi( const std::string& displayed_text, const int value, const int y_pos );
}
