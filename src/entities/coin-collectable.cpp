#include "coin-collectable.h"
#include "entity.h"
#include "../score-manager.h"
#include "../random-generation.h"

#include <array>
#include <cassert>

CoinCollectable::CoinCollectable( const int pos_x, const int pos_y, const bool is_hidden, const std::vector<std::string>& texture_paths )
  : Entity(pos_x, pos_y, is_hidden, texture_paths ) {}

int CoinCollectable::GivePoints( ScoreManager& score_manager )
{
  constexpr std::array<int , 6> score_to_give { 2500, 2000, 1400, 1000, 700, 400 };
  
  assert( score_to_give.size() == score_manager.score_thresholds.size() );

  for (int index = 0; index < score_manager.score_thresholds.size(); ++index )
  {
    if ( score_manager.current_score > score_manager.score_thresholds[ index ])
    {
      if ( RandomGeneration::HasHitThreshold(::RandomGeneration::NumberBetween(1, 100), 25))
      {
        return score_to_give[ index ] * 2;
      }
      return score_to_give[ index ];     
    }
  }

  score_manager.addToScoreMultiplier( 1 );
  constexpr int default_score_given = 300;
  return default_score_given;
}

void CoinCollectable::respawnToNewLocation()
{
  setHidden( false );
  m_pos_x = RandomGeneration::NumberBetween( 300, 1400);
  m_pos_y = RandomGeneration::NumberBetween( 200, 700);
}

CoinCollectable::EntityType CoinCollectable::getEntityType()
{
  return CoinCollectable::EntityType::friendly;
}
