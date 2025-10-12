#include <string>

#include "player.h"
#include "../window.h"
#include "entity.h"

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

void Player::changePlayerCursor( Window& game_window, Entity& collided_entity )
{
  
  switch (collided_entity.getEntityType()) 
  {
    case Entity::EntityType::hostile:
      drawToScreen
      ( 
          static_cast<int>( TextureName::targeted ), 
          game_window.getCursorX() - cursor_offset, 
          game_window.getCursorY() - cursor_offset
      );
      return;

    case Entity::EntityType::friendly:
      drawToScreen
      ( 
          static_cast<int>( TextureName::targeted_friendly ), 
          game_window.getCursorX() - cursor_offset, 
          game_window.getCursorY() - cursor_offset
      );
      return;

    default:
      changePlayerCursor( game_window );
  }
}

void Player::changePlayerCursor( Window& game_window )
{
  drawToScreen
  ( 
      static_cast<int>( TextureName::not_targeted ), 
      game_window.getCursorX() - cursor_offset, 
      game_window.getCursorY() - cursor_offset
  );
  return;
}
