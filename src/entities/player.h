#pragma once

#include "entity.h"
#include "../window.h"

#include <raylib.h>

class Player : public Entity
{
  public:
    Player
    ( 
      const int pos_x, 
      const int pos_y, 
      const std::vector<std::string>& texture_paths 
    );

    enum class TextureName 
    {
      not_targeted = 0,
      targeted = 1,
      targeted_friendly = 2
    };

    int addToScore(int score_to_add);
    void changePlayerCursor( TextureName texture_to_swap_to, Window& game_window );

    int current_score { 0 };
    int fire_damage { 2 };

  private:
};
