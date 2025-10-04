#include "player.h"

int Player::addToScore(const int score_to_add) 
{
  m_current_score += score_to_add;

  constexpr int maximum_score { 99999 };
  if ( m_current_score > maximum_score ) 
  {
    m_current_score = maximum_score;
  }
  return m_current_score;
};

