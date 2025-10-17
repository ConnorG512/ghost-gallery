#pragma once
#include <raylib.h>

class Ui {
public:
  Ui(const int start_pos_x, const int start_pos_y, const int spacing,
     const int font_size = 32);

protected:
  int m_start_position_x{10};
  int m_start_position_y{10};
  int m_spacing{30};
  int m_font_size{32};
};
