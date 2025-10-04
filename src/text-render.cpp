#include "text-render.h"
#include <raylib.h>


void TextRender::drawTextToScreen(const std::string& displayed_text, const int pos_x, const int pos_y, const int size)
{
  DrawText(displayed_text.c_str(), pos_x, pos_y, size, WHITE);
}
