#pragma once 

#include "collectable.h"

class HeartCollectable : public Collectable
{
  public:
    HeartCollectable
    (
      const std::vector<std::string>& texture_paths,
      const int max_health,
      const int current_health,
      const int x_pos = 0,
      const int y_pos = 0,
      const bool is_visible = true,
      const int health_provided = 2
    );

    void givePoweUp(Player& current_player) override;

  private:
    int m_health_restored { 2 };
};
