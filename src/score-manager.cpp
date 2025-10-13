#include "score-manager.h"
#include <limits>

int ScoreManager::increaseScore( int num_to_increase_by )
{
  constexpr int max_score { std::numeric_limits<int>::max() };

  current_score += num_to_increase_by;
  if ( current_score == max_score )
  {
    current_score = max_score;
  }
  return current_score;
}

void ScoreManager::resetCurrentScore()
{
  current_score = 0;
}
