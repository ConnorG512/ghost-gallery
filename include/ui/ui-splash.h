#pragma once

#include "ui/ui.h"

#include <array>

class UiSplash : public Ui
{
  public:
    UiSplash(const int start_pos_x, const int start_pos_y, const int spacing, const int font_size = 32);

    void drawUi(const int& player_high_score);
};
