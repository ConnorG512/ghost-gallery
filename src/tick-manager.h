#pragma once

#include <array>
#include <cstdint>

class TickManager 
{
  public:
    void incrementTick();
    int& getCurrentTick();
    bool hasHitTick( int tick_to_check );
    void resetTickCounter();
};
