#pragma once

class Player 
{
  public:
    Player(int current_lives);
    ~Player();
    int calculateScore(int score_to_add);
    int reduceLives(int num_to_reduce);

  private:
    int m_current_score { 0 };
    int m_current_lives { 0 };
};
