#include <string>

#include "player.h"
namespace 
{
  constexpr int cursor_offset { 64 };
}

Player::Player
( 
    const int pos_x, 
    const int pos_y, 
    const std::vector<std::string>& texture_paths
)
  : Entity 
    { 
      pos_x, 
      pos_y, 
      { 
        "assets/image/ui/cursor-target.png", 
        "assets/image/ui/cursor-target-found.png",
        "assets/image/ui/cursor-target-found-friendly.png"
      }
    } {}

int Player::addToScore(const int score_to_add) 
{
  current_score += score_to_add;

  constexpr int maximum_score { 99999 };
  if ( current_score > maximum_score ) 
  {
    current_score = maximum_score;
  }
  return current_score;
};

void Player::changePlayerCursor( TextureName texture_to_swap_to, Window& game_window )
{
  switch (texture_to_swap_to) 
  {
    case TextureName::not_targeted:
      drawToScreen( 
          static_cast<int>( TextureName::not_targeted ), 
          game_window.getCursorX() - cursor_offset, 
          game_window.getCursorY() - cursor_offset
      );
      break;

    case TextureName::targeted:
      drawToScreen( 
          static_cast<int>( TextureName::targeted ), 
          game_window.getCursorX() - cursor_offset, 
          game_window.getCursorY() - cursor_offset 
      );
      break;
    
    case TextureName::targeted_friendly:
      drawToScreen( 
          static_cast<int>( TextureName::targeted_friendly ), 
          game_window.getCursorX() - cursor_offset, 
          game_window.getCursorY() - cursor_offset 
      );
      break;
  }
}
