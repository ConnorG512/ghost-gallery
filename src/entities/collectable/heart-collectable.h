#pragma once

#include "collectable.h"

class HeartCollectable : public Collectable {
public:
  HeartCollectable(const int x_pos = 0, const int y_pos = 0,
                   const bool is_visible = true, const int health_provided = 2);

  void givePoweUp(Player &current_player) override;
  void playSound(AudioManager &audio_manager) override;

private:
  int m_health_restored{2};
};
