#pragma once

#include "gamestate-base.h"
#include "../image-sprite.h"
#include "../entities/enemy.h"
#include "../random-generation.h"
#include "../entities/player.h"
#include "../tick-manager.h"
#include "../entities/heart-collectable.h"
#include "../score-manager.h"
#include "../entities/coin-collectable.h"
#include <array>

class GameStateGameplay : public GameState
{
  public: 
    GameStateGameplay( GameManager* game_manager, Window& game_window, ScoreManager& score_manager, AudioManager& audio_manager );
    void initialiseState() override;
    void inputLoop() override;
    void gameplayLoop() override;

  protected:
    ImageSprite m_background_image {{ "assets/image/background/manor-1.png" }, 0, 0 };
    TickManager m_game_tick {};
    
    Enemy m_enemy_sprite 
    {
      2,
      RandomGeneration::NumberBetween(0, 1600),
      RandomGeneration::NumberBetween(0, 900),
      { "assets/image/entity/enemy/ghost/ghost-1.png" },
      2
    };

    Player m_player 
    {
      0, 
      0, 
      {
        "assets/image/ui/cursor-target.png", 
        "assets/image/ui/cursor-target-found.png"
      }
    };
    
    HeartCollectable m_heart_collectable
    {
      RandomGeneration::NumberBetween(0, 1600),
      RandomGeneration::NumberBetween(0, 900),
      true,
      { "assets/image/entity/heart/heart-pickup.png" }
    };

    CoinCollectable m_coin_collectable
    {
      RandomGeneration::NumberBetween( 200, 1300 ),
      RandomGeneration::NumberBetween( 150, 750 ),
      true,
      { "assets/image/entity/coin/coin.png" }
    };

    void playerShoot();
    void respawnEnemy();
    void resetEnemyOnTick();
    void startTickEvent();
    void drawGameUi();
    void gameOver();
    void drawSprites();
    void playerClickedHeartPickup();
    void spawnCollectables();
    void checkEntityCollisions();
    bool hasPlayerDied();
}; 
