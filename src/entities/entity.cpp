#include "entity.h"
#include "../audio-manager.h"
#include "components/positional-component.h"

Entity::Entity(const std::vector<std::string> &texture_paths,
               const int max_health, const int current_health, const int x_pos,
               const int y_pos)
    : sprite{texture_paths}, health_component{max_health, current_health},
      collision{{x_pos, y_pos}}, positional_component{x_pos, y_pos}
{
}

bool Entity::checkCollision(const Rectangle &collider)
{
    return collision.IsCollidingWith(collider);
}

void Entity::setNewEntityPosition(std::array<int, 2> xy_pos)
{
    positional_component.setScreenPosition(xy_pos);
    collision.updateCollisionPosition(xy_pos);
}

void Entity::playSound(AudioManager &audio_manager)
{
    audio_manager.playAudio(AudioManager::SoundId::ghost_death);
}
