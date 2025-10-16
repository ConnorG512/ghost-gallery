#pragma once

#include <string>
#include <raylib.h>

namespace TextRender 
{
  void drawTextToScreen(const std::string& displayed_text, const int pos_x = 0, const int pos_y = 0, const int size = 32 );
}
