#pragma once

#include "../entities/components/tick-component.h"
#include <vector>

class SpawnManager
{
  public:
    void setNewSpawnSlotsNum(const int slots);

  protected:
    SpawnManager(const int num_spawn_slots);

    int m_num_available_slots{3};
};
