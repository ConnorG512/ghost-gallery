#include "player.h"

Player::Player(int current_lives)
  : m_current_lives { current_lives } {};

Player::~Player() {};

int Player::addToScore(const int score_to_add) 
{
  m_current_score += score_to_add;

  constexpr int maximum_score { 999999 };
  if ( m_current_score > maximum_score ) 
  {
    m_current_score = maximum_score;
  }
  return m_current_score;
};
int Player::reduceLives(const int num_to_reduce) 
{
  m_current_lives -= num_to_reduce;
  if ( m_current_lives <= 0 )
  {
    m_current_lives = 0;
  }
  return m_current_lives;
};
