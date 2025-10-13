#pragma once

#include "score-manager.h"
#include <array>

struct ScoreManager
{
    int increaseScore( int num_to_increase_by );
    void resetCurrentScore();
    int current_score { 0 };
    std::array<int, 6> score_thresholds { 50000, 35000 , 20000, 17500, 12500, 9000 };
};
