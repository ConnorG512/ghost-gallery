#pragma once

#include <array>

class PositionalComponent
{
  public:
    PositionalComponent(int x_pos = 0, int y_pos = 0);

    void setScreenPosition(const std::array<int, 2>& xy_positions);
    std::array<int, 2>& GetXYPos();

  private:
    std::array<int, 2> m_current_position { 0, 0 };
};
