#pragma once

#include "components/movement-component.h"
#include "../collision-shape.h"
#include "components/health-component.h"
#include "../image-sprite.h"

#include <raylib.h>
#include <string>
#include <vector>

class AudioManager;

class Entity 
{
  public:
    Entity
    (
      const std::vector<std::string>& texture_paths,
      const int max_health,
      const int current_health,
      const int x_pos,
      const int y_pos
    );
    virtual ~Entity() = default;

    bool checkCollision( const Rectangle& collider );
    void moveSprite( const int x_pos, const int y_pos, const int texture_index = 0 );

    virtual void playSound( AudioManager& audio_manager );
    
    ImageSprite sprite;
    HealthComponent health_component { };
    CollisionShape collision;
    MovementComponent movement_component;
};
