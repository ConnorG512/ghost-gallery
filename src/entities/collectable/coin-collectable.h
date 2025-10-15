#pragma once

#include "collectable.h"

class CoinCollectable : public Collectable
{
  public:
    CoinCollectable
    (
      const std::vector<std::string>& texture_paths,
      const int max_health,
      const int current_health,
      const int x_pos = 0,
      const int y_pos = 0,
      const bool is_visible = true,
      const int coins_given = 300
    );

    void givePoweUp(Player& current_player) override;

  private:
    int m_score_given { 300 };

};
