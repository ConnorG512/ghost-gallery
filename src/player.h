#pragma once

#include "entity.h"
#include "window.h"

#include <raylib.h>

class Player : public Entity
{
  public:
    Player( 
      const int pos_x, 
      const int pos_y, 
      const std::string& texture_path, 
      const std::string& texture_path_2, 
      const int coll_width, 
      const int coll_height
    );

    enum class TextureName 
    {
      not_targeted,
      targeted,
    };

    int addToScore(int score_to_add);
    void changePlayerCursor( TextureName texture_to_swap_to, Window& game_window );

    int current_score { 0 };
    int fire_damage { 2 };

  private:
};
