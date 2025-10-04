#include "player.h"

Player::Player() {};
Player::Player(int max_health, int current_health )
  : m_player_health { max_health, current_health } {}

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

int Player::takeDamage( int health_to_reduce )
{
  return m_player_health.reduceHealth( health_to_reduce );
  
}
int Player::recieveHealth( int health_to_add)
{
  return m_player_health.increaseHealth( health_to_add );
}
