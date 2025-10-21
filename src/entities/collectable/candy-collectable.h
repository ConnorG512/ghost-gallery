#pragma once

#include "collectable.h"
#include <vector>

class CandyCollectable : public Collectable
{
  public:
    CandyCollectable(const int x_pos, const int y_pos, const int multiplier_amount);
    virtual ~CandyCollectable() = default;

    virtual void givePowerUp(Player& current_player);
    virtual void playSound(AudioManager& audio_manager);

  private:
    int m_multiplier_to_give{2};
};
