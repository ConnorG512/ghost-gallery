#include <string>

#include "player.h"
#include "entity.h"

namespace 
{ 
  constexpr int cursor_offset { 64 };
}

Player::Player
(
  const std::vector<std::string>& texture_paths,
  const int max_health,
  const int current_health,
  const int x_pos,
  const int y_pos
) 
  : Entity { texture_paths, max_health, current_health, x_pos, y_pos } {}

void Player::ResetPlayerStats()
{
  health_component.resetHealthToMax();
  score_component.resetScore();
}
