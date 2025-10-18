#include "positional-component.h"

PositionalComponent::PositionalComponent(int x_pos, int y_pos)
    : m_current_position{x_pos, y_pos} { }

void PositionalComponent::setScreenPosition(const std::array<int, 2>& xy_positions)
{
  for ( auto& coord : xy_positions )
  {
    m_current_position = { xy_positions.at(0), xy_positions.at(1)};
  }
}

std::array<int, 2>& PositionalComponent::GetXYPos()
{
  return m_current_position;
}
