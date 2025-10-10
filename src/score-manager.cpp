#include "score-manager.h"
#include <limits>

int ScoreManager::increaseScore( int num_to_increase_by )
{
  constexpr int max_score { std::numeric_limits<int>::max() };

  m_current_score += num_to_increase_by;
  if ( m_current_score == max_score )
  {
    m_current_score = max_score;
  }
  return m_current_score;
}
