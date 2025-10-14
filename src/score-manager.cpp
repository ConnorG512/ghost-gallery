#include "score-manager.h"
#include <iostream>
#include <limits>
#include <ostream>

void ScoreManager::increaseScore( int num_to_increase_by )
{
  constexpr int max_score { std::numeric_limits<int>::max() };

  current_score += ( num_to_increase_by * current_multiplier );
  if ( current_score >= max_score )
  {
    current_score = max_score;
  }
}

void ScoreManager::resetScoreManager()
{
  current_score = 0;
  current_multiplier = 1;
}

void ScoreManager::addToScoreMultiplier( int multiplier )
{
  current_multiplier += multiplier;
  std::cout << "Multiplier: " << current_multiplier << std::endl;
}

void ScoreManager::checkForNewHighScore()
{
  if ( current_score > high_score )
  {
    high_score = current_score;
  }
}
