#pragma once

#include "score-manager.h"
#include <array>

struct ScoreManager
{
    void increaseScore( int num_to_increase_by );
    void addToScoreMultiplier ( int multiplier );
    void resetScoreManager();
    void checkForNewHighScore();
    
    int current_score { 0 };
    int high_score { 0 };
    int current_multiplier { 1 };
    std::array<int, 6> score_thresholds { 50000, 35000 , 20000, 17500, 12500, 9000 };
};
