#include "coin-collectable.h"
#include "../score-manager.h"
#include "entity.h"

#include <array>

CoinCollectable::CoinCollectable( const int pos_x, const int pos_y, const bool is_hidden, const std::vector<std::string>& texture_paths )
  : Entity(pos_x, pos_y, is_hidden, texture_paths ) {}

int CoinCollectable::GivePoints( ScoreManager& score_manager )
{
  constexpr std::array<int, 3> score_thresholds { 700, 1200, 1500 };
  constexpr std::array<int, 3> score_amounts { 500, 750, 900 };
  constexpr int bonus_chance { 10 };

  return 300;
}
