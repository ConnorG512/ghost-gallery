#include "include/util/random-generation.h"
#include <cassert>
#include <random>

int RandomGeneration::GenerateRandomNumber(const int min, const int max)
{
    assert(min < max && "Min value cannot be bigger than the max!");

    std::random_device seed;
    std::mt19937 rd{seed()};
    std::uniform_int_distribution<int> uid(min, max);

    return uid(rd);
}

bool RandomGeneration::HasHitRandomNumberThreshold(const int threshold, const int min, const int max)
{
    const int result{GenerateRandomNumber(min, max)};
    return result < threshold;
}
