#pragma once

#include <cstdint>

class TickManager 
{
  public:
    void incrementTick();
    uint64_t& getCurrentTick();
    bool hasHitTick( int tick_to_check );
    void resetTickCounter();
};
