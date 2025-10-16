#pragma once

#include "gamestate-base.h"
#include "../image-sprite.h"
#include "../tick-manager.h"
#include "../entities/player.h"
#include "../spawn-manager.h"
#include "../game-ui.h"
#include "../entities/enemy.h"
#include "../random-generation.h"

class Collectable;

class GameStateGameplay : public GameState
{
  public: 
    GameStateGameplay( GameManager* game_manager, Window& game_window, Player& current_player, AudioManager& audio_manager );
    void initialiseState() override;
    void inputLoop() override;
    void gameplayLoop() override;

    ~GameStateGameplay();

  protected:
    ImageSprite m_background_image {{ "assets/image/background/manor-1.png" }, 0, 0 };
    TickManager m_game_tick {};

    SpawnManager m_collectable_spawn_manager { };
    GameUi m_game_ui { 10, 10 };

    Enemy m_enemy { 
      { "assets/image/entity/enemy/ghost/ghost-1.png" },
      2,
      2,
      RandomGeneration::NumberBetween( 100, 1500 ),
      RandomGeneration::NumberBetween( 100, 600 ),
    };
    
    void onGameTicks();
    void onEnemyClicked();
}; 
