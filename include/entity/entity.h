#pragma once

#include "component/collision-shape.h"
#include "component/image-sprite.h"
#include "component/health-component.h"
#include "component/positional-component.h"

#include <array>
#include <raylib.h>
#include <string>
#include <vector>

class AudioManager;

class Entity
{
  public:
    void setNewEntityPosition(std::array<int, 2> xy_pos = {0, 0});

    virtual void playSound(AudioManager& audio_manager);

    ImageSprite sprite;
    HealthComponent health_component{};
    CollisionShape collision{};
    PositionalComponent positional_component{};

  protected:
    Entity(const std::vector<std::string>& texture_paths,
           const int max_health,
           const int current_health,
           const int x_pos,
           const int y_pos);
    virtual ~Entity() = default;
};
