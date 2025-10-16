#include "coin-collectable.h"
#include "../player.h"
#include "../../random-generation.h"

CoinCollectable::CoinCollectable
(
  const std::vector<std::string>& texture_paths,
  const int max_health,
  const int current_health,
  const int x_pos,
  const int y_pos,
  const bool is_visible,
  const int coins_given
) : Collectable { texture_paths, max_health, current_health, x_pos, y_pos, is_visible }
  , m_score_given { coins_given } {}

void CoinCollectable::givePoweUp( Player& current_player )
{
  if ( RandomGeneration::HasHitThreshold(RandomGeneration::NumberBetween(), 35 ))
  {
    current_player.score_component.addToScoreMultiplier( 1 );
  }
  current_player.score_component.increaseScore( m_score_given );
}
