#pragma once

#include "entity/collectable.h"
#include <vector>

class CandyCollectable : public Collectable
{
  public:
    CandyCollectable(const int x_pos, const int y_pos, const int multiplier_amount);

    void givePowerUp(Player& current_player) override;
    void playSound(AudioManager& audio_manager) override;

  private:
    int m_multiplier_to_give{2};
};
