#pragma once

#include "gamestate-base.h"
#include "../image-sprite.h"
#include "../entity.h"
#include "../random-generation.h"
#include "../player.h"

class GameStateGameplay : public GameState
{
  public: 
    GameStateGameplay( Window& game_window );
    void initialiseState() override;
    void inputLoop() override;
    void gameplayLoop() override;

    void playerShoot();
    void changePlayerCursor();

  protected:
    ImageSprite m_background_image { "assets/image/background/manor-1.png", 0, 0 };
    
    Entity m_enemy_sprite {
      RandomGeneration::generateRandomNumberBetween(0, 1600),
      RandomGeneration::generateRandomNumberBetween(0, 900),
      "assets/image/entity/enemy/default/default.png",
      128,
      128,
    };
    
    Player m_player {
      0, 
      0, 
      "assets/image/ui/cursor-target.png", 
      "assets/image/ui/cursor-target-found.png",
      128, 
      128,
    };
};
