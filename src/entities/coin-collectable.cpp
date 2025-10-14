#include "coin-collectable.h"
#include "entity.h"
#include "../score-manager.h"
#include "../random-generation.h"
#include <format>
#include <iostream>
#include <string>

CoinCollectable::CoinCollectable( const int pos_x, const int pos_y, const bool is_hidden, const std::vector<std::string>& texture_paths )
  : Entity(pos_x, pos_y, is_hidden, texture_paths ) {}

int CoinCollectable::GivePoints( ScoreManager& score_manager )
{
  if ( RandomGeneration::HasHitThreshold(RandomGeneration::NumberBetween(1, 100), 65))
  {
    increaseScoreMultiplier( score_manager );
  }

  for ( const auto& score_threshold : score_manager.score_thresholds )
  {
    if ( score_manager.current_score > score_threshold )
    {
      std::cout << std::format("Score Bigger than: {}!", std::to_string( score_threshold )) << std::endl;
      
      constexpr int score_threshold_division_amount { 4 };
      return RandomGeneration::NumberBetween( 250, 400 ) + ( score_threshold / score_threshold_division_amount );
      break;
    }
  }
  
  return RandomGeneration::NumberBetween( 250, 400 );
}

void CoinCollectable::respawnToNewLocation()
{
  setHidden( false );
  m_pos_x = RandomGeneration::NumberBetween( 300, 1400 );
  m_pos_y = RandomGeneration::NumberBetween( 200, 700 );
}

CoinCollectable::EntityType CoinCollectable::getEntityType()
{
  return CoinCollectable::EntityType::friendly;
}

void CoinCollectable::increaseScoreMultiplier( ScoreManager& score_manager )
{
  constexpr int multiplier_increase_num { 1 };
  score_manager.addToScoreMultiplier( multiplier_increase_num );
}
