#pragma once

#include "include/ui/ui.h"
#include <array>

class UiGameplay : public Ui
{
  public:
    UiGameplay(const int start_pos_x, const int start_pos_y, const int spacing, const int font_size = 32);

    void drawUi(const std::array<int, 3>& player_stats);

  private:
};
