#include "heart-collectable.h"
#include "../player.h"
#include "../../audio-manager.h"

HeartCollectable::HeartCollectable
(
  const int x_pos,
  const int y_pos,
  const bool is_visible,
  const int health_provided
) : Collectable { { "assets/image/entity/heart/heart-pickup.png" }, 1, 1, x_pos, y_pos, is_visible }
  , m_health_restored { health_provided } {}

void HeartCollectable::givePoweUp( Player& current_player )
{
  current_player.health_component.IncreaseHealthBy( m_health_restored );
}

void HeartCollectable::playSound( AudioManager& audio_manager )
{
  audio_manager.playAudio( AudioManager::SoundId::heart_pickup );
}
