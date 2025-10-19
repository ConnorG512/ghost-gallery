#pragma once

#include "../entities/components/tick-component.h"
#include <vector>

class SpawnManager
{
  public:
    SpawnManager(const int tick_threshold, const int num_spawn_slots);

    void setNewSpawnSlotsNum(const int slots);

  protected:
    TickComponent m_ticker{600};
    int m_num_available_slots{3};
};
