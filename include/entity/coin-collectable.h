#pragma once

#include "collectable.h"
#include <raylib.h>

class CoinCollectable : public Collectable
{
  public:
    CoinCollectable(const int x_pos = 0, const int y_pos = 0, const int coins_given = 300);

    void givePowerUp(Player& current_player) override;
    void playSound(AudioManager& audio_manager) override;

  private:
    int m_score_given{300};
};
