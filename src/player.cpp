#include "player.h"
#include <iostream>
#include <print>

Player::Player(int current_lives)
  : m_current_lives { current_lives } {};

Player::~Player() {};

int Player::calculateScore(int score_to_add) {
  // TODO
  std::println("STUB: calculateScore called!");
  return 0;
};
int Player::reduceLives(int num_to_reduce) {
  // TODO
  std::println("STUB: reduceLives called!");
  return 0;
};
