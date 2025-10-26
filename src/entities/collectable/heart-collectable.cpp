#include "entity/heart-collectable.h"
#include "entity/player.h"
#include "manager/audio-manager.h"

HeartCollectable::HeartCollectable(const int x_pos, const int y_pos, const int health_provided)
    : Collectable{{"assets/image/entity/heart/heart-pickup.png"}, x_pos, y_pos}, m_health_restored{health_provided}
{
}

void HeartCollectable::givePowerUp(Player& current_player)
{
    current_player.health_component.IncreaseHealthBy(m_health_restored);
}

void HeartCollectable::playSound(AudioManager& audio_manager)
{
    audio_manager.playAudio(AudioManager::SoundId::heart_pickup);
}
