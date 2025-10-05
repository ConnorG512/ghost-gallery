#pragma once

#include "player.h"
#include "window.h"
#include "image-sprite.h"
#include "text-render.h"
#include "entity.h"
#include "random-generation.h"

class GameManager
{
  public:
    void initialiseApplication();
    void drawUpdatePerTick();
    void inputUpdatePerTick();
    bool shouldGameClose();
    
  private:
    Window game_window { 1600, 900, 60 };
    Player player_instance { 0, 0, "assets/image/ui/cursor-target.png", 128, 128 };

    ImageSprite background_sprite { "assets/image/default-background.png", 0, 0 };
    Entity enemy_sprite { RandomGeneration::generateRandomNumberBetween(0, 1600), RandomGeneration::generateRandomNumberBetween(0, 900), "assets/image/entity/enemy/default/default.png", 128, 128 };
};
