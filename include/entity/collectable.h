#pragma once

#include "entity/entity.h"

class Player;

class Collectable : public Entity
{
  public:
    Collectable(const std::vector<std::string>& texture_paths, const int x_pos = 0, const int y_pos = 0);
    virtual ~Collectable() = default;
    virtual void givePowerUp(Player& current_player) = 0;
};
