#include "player.h"
#include <iostream>

Player::Player(int current_lives)
  : m_current_lives { current_lives } {};

Player::~Player() {};

int Player::calculateScore(int score_to_add) {
  // TODO
  std::cout << "STUB: calculateScore called!" << std::endl;
  return 0;
};
int Player::reduceLives(int num_to_reduce) {
  // TODO
  std::cout << "STUB: reduceLives called!" << std::endl;
  return 0;
};
