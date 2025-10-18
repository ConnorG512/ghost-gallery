#pragma once

#include "../entities/components/tick-component.h"
#include <vector>

class SpawnManager
{
  public:
    SpawnManager(const int tick_threshold);
    virtual ~SpawnManager() = default;

    bool IsSpawnerReady();
    void drawSpawnedObjects();
    int SetNewSpawnSlotsNum(const int slots);
    virtual bool HasPlayerInteracted();

  private:
    TickComponent m_ticker{600};
};
