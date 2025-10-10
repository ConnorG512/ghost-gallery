#pragma once

#include "score-manager.h"

struct ScoreManager
{
  public:
    int increaseScore( int num_to_increase_by );
    int m_current_score { 0 };
};
