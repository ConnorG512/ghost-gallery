#include "random-generation.h"

int RandomGeneration::NumberBetween(const int min, const int max) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(min, max);

  return distrib(gen);
}

bool RandomGeneration::HasHitThreshold(const int number,
                                       const int success_threshold) {
  return number <= success_threshold;
}
