#include "enemy.h"

Enemy::Enemy
(
    
  const std::vector<std::string>& texture_paths,
  const int max_health,
  const int current_health,
  const int x_pos,
  const int y_pos,
  const int score_to_give 
) 
  : Entity { texture_paths, max_health, current_health, x_pos, y_pos }
  , m_score_to_give { score_to_give } {}

