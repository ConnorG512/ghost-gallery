#pragma once

#include "player.h"
#include "window.h"
#include "image-sprite.h"
#include "text-render.h"
#include "entity.h"

class GameManager
{
  public:
    void initialiseApplication();
    void drawUpdatePerTick();
    void inputUpdatePerTick();
    bool shouldGameClose();
    
  private:
    Window game_window { 1600, 900, 60 };
    Player player_instance { 6 };

    ImageSprite background_sprite { "assets/image/default-background.png", 0, 0 };
    ImageSprite cursor_sprite { "assets/image/ui/cursor-target.png", 0, 0 };
    Entity enemy_sprite { 1600 / 2 -64, 900 / 2 -64, "assets/image/entity/enemy/default/default.png"}

};
