#pragma once

#include "entity/enemy.h"
#include "entity/player.h"
#include "component/image-sprite.h"
#include "manager/spawn-manager-collectable.h"
#include "manager/spawn-manager-enemy.h"
#include "ui/ui-gameplay.h"
#include "util/random-generation.h"
#include "game-state/gamestate-base.h"

class Collectable;

class GameStateGameplay : public GameState
{
  public:
    GameStateGameplay(GameManager* game_manager,
                      WindowManager& game_window,
                      Player& current_player,
                      AudioManager& audio_manager);
    ~GameStateGameplay() = default;

    void initialiseState() override;
    void gameplayLoop() override;
    void renderingLoop() override;

  protected:
    ImageSprite m_background_image{{"assets/image/background/manor-1.png"}};
    SpawnManagerCollectable m_collectable_spawn_manager{5};
    SpawnManagerEnemy m_enemy_spawn_manager{1};
    UiGameplay m_ui{10, 10, 40};

    void onGameTicks();
    void gameOver();
    void playerCollisionActions();
};
