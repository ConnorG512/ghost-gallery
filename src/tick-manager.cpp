#include "tick-manager.h"

#include <cstdint>

namespace 
{
  uint64_t current_tick { 0 };
}

void TickManager::incrementTick()
{
  constexpr uint64_t max_tick_amount { 120 };
  current_tick ++;

  if ( current_tick > max_tick_amount )
  {
    current_tick = 0;
  }
}

uint64_t& TickManager::getCurrentTick()
{
  return current_tick;
}

bool TickManager::hasHitTick( int tick_to_check )
{
  return current_tick == tick_to_check;
}

void TickManager::resetTickCounter()
{
  current_tick = 0;
}
