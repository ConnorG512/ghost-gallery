#pragma once

#include "../entities/components/tick-component.h"
#include <vector>

class SpawnManager
{
  public:
    SpawnManager(const int num_spawn_slots);

    void setNewSpawnSlotsNum(const int slots);

  protected:
    int m_num_available_slots{3};
};
