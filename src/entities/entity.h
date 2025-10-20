#pragma once

#include "../collision-shape.h"
#include "../image-sprite.h"
#include "components/health-component.h"
#include "components/positional-component.h"

#include <array>
#include <raylib.h>
#include <string>
#include <vector>

class AudioManager;

class Entity
{
  public:
    Entity(const std::vector<std::string>& texture_paths,
           const int max_health,
           const int current_health,
           const int x_pos,
           const int y_pos);
    virtual ~Entity() = default;

    bool checkCollision(const Rectangle& collider);
    void setNewEntityPosition(std::array<int, 2> xy_pos = {0, 0});

    virtual void playSound(AudioManager& audio_manager);

    ImageSprite sprite;

    HealthComponent health_component{};
    CollisionShape collision{};
    PositionalComponent positional_component{};
};
