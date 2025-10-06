#include "player.h"
#include <string>

Player::Player( const int pos_x, const int pos_y, const std::string& texture_path, const std::string& texture_path_2, const int coll_width, const int coll_height )
  : Entity{ pos_x, pos_y, texture_path, texture_path_2, coll_width, coll_height } {}

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

