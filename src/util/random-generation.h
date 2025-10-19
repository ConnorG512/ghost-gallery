#pragma once

#include <random>

namespace RandomGeneration
{
int GenerateRandomNumber(const int min = 1, const int max = 100);
bool HasHitRandomNumberThreshold(const int threshold, const int min = 1,
                                 const int max = 100);
}; // namespace RandomGeneration
