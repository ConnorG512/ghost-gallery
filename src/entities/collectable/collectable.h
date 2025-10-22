#pragma once

#include "../entity.h"

class Player;

class Collectable : public Entity
{
  public:
    Collectable(const std::vector<std::string>& texture_paths,
                const int x_pos = 0,
                const int y_pos = 0,
                const bool is_visible = true);
    virtual ~Collectable() = default;
    virtual void givePowerUp(Player& current_player) = 0;

  private:
    bool m_is_visible{false};
};
