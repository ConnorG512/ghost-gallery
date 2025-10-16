#include "score-component.h"
#include <limits>

void ScoreComponent::increaseScore( int num_to_increase_by )
{
  constexpr int max_score { std::numeric_limits<int>::max() };

  current_score += ( num_to_increase_by * current_multiplier );
  if ( current_score >= max_score - 1 )
  {
    current_score = max_score;
  }
}

void ScoreComponent::resetScore()
{
  current_score = 0;
  current_multiplier = 1;
}

void ScoreComponent::addToScoreMultiplier( int multiplier )
{
  current_multiplier += multiplier;
}

void ScoreComponent::checkForNewHighScore()
{
  if ( current_score > high_score )
  {
    high_score = current_score;
  }
}
