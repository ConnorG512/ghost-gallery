#pragma once

#include <string>
#include <raylib.h>

namespace TextRender 
{
    void drawTextToScreen(const std::string& displayed_text, const int pos_x, const int pos_y, const int size);
}
