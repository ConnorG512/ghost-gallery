#pragma once

#include "entity.h"
#include "../damage-component.h"

class Window;

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

    DamageComponent damage_component { 2, 30, 1 };
};
