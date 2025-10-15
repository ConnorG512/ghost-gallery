#pragma once

#include <random>

namespace RandomGeneration
{
  int NumberBetween( const int min = 1, const int max = 100);
  bool HasHitThreshold(const int number, const int success_threshold );
}
