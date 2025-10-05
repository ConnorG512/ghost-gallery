#pragma once

#include <cstdint>

class TickManager 
{
  public:
    void incrementTick();
    uint64_t& getCurrentTick();
};
