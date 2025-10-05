#include "tick-manager.h"

#include <cstdint>

namespace 
{
  uint64_t current_tick { 0 };
}

void incrementTick()
{
  constexpr uint64_t max_tick_amount { 60 };
  current_tick ++;

  if ( current_tick == max_tick_amount )
  {
    current_tick = 0;
  }
}

uint64_t& TickManager::getCurrentTick()
{
  return current_tick;
}


