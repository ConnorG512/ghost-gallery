#pragma once

#include "component/score-component.h"
#include <array>

struct ScoreComponent
{
    void increaseScore(int num_to_increase_by);
    void addToScoreMultiplier(int multiplier);
    void resetScore();
    void checkForNewHighScore();

    int current_score{0};
    int high_score{0};
    int current_multiplier{1};
};
