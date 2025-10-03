#pragma once

class Player 
{
  public:
    Player(int current_lives);
    ~Player();
    int addToScore(int score_to_add);
    int reduceLives(int num_to_reduce);
    
    int m_current_score { 0 };

  private:
    int m_current_lives { 0 };
};
