#include "player.h"
#include "entity.h"
#include <utility>

namespace {
constexpr int cursor_offset{64};
}

Player::Player(const int x_pos, const int y_pos)
    : Entity{{"assets/image/ui/cursor-target.png",
              "assets/image/ui/cursor-target-found.png",
              "assets/image/ui/cursor-target-found-friendly.png"},
             8,
             8,
             x_pos,
             y_pos} {}

void Player::ResetPlayerStats() {
  health_component.resetHealthToMax();
  score_component.resetScore();
}

void Player::drawPlayerCursor(const CursorType cursor_to_change_to) {
  moveSprite(user_input.GetMousePos().at(0), user_input.GetMousePos().at(1),
             std::to_underlying(cursor_to_change_to));
}
