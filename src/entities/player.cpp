#include <string>

#include "player.h"
#include "entity.h"

namespace 
{ 
  constexpr int cursor_offset { 64 };
}

Player::Player
(
  const int x_pos,
  const int y_pos
) 
  : Entity { 
    {
      "assets/image/ui/cursor-target.png",
      "assets/image/ui/cursor-target-found.png",
      "assets/image/ui/cursor-target-found-friendly.png"
    },
    8,
    8,
    x_pos, y_pos } {}

void Player::ResetPlayerStats()
{
  health_component.resetHealthToMax();
  score_component.resetScore();
}
