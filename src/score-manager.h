#pragma once

#include "score-manager.h"

struct ScoreManager
{
  public:
    int increaseScore( int num_to_increase_by );
    int current_score { 0 };
};
