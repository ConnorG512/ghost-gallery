#include "heart-collectable.h"
#include "../player.h"

HeartCollectable::HeartCollectable
(
  const std::vector<std::string>& texture_paths,
  const int max_health,
  const int current_health,
  const int x_pos,
  const int y_pos,
  const bool is_visible,
  const int health_provided
) : Collectable { texture_paths, max_health, current_health, x_pos, y_pos, is_visible }
  , m_health_restored { health_provided } {}

void HeartCollectable::givePoweUp( Player& current_player )
{
  current_player.health_component.increaseHealth( m_health_restored );
}
