#include "tick-manager.h"

#include <cstdint>
#include <limits>

namespace 
{
  uint64_t current_tick { 0 };
}

void TickManager::incrementTick()
{
  constexpr uint64_t max_tick_amount { std::numeric_limits<int>::max() };
  current_tick ++;

  if ( current_tick > max_tick_amount - 1 )
  {
    resetTickCounter();
  }
}

bool TickManager::hasHitTick( int tick_to_check )
{
  // Returns true every tick_to_check increments.
  // Eg tick_to_check = 30, every 30 increments.
  return current_tick % tick_to_check == 0;
}

void TickManager::resetTickCounter()
{
  current_tick = 0;
}
