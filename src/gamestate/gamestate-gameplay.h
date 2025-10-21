#pragma once

#include "../entities/enemy.h"
#include "../entities/player.h"
#include "../image-sprite.h"
#include "../spawner/spawn-manager-collectable.h"
#include "../spawner/spawn-manager-enemy.h"
#include "../ui/ui-gameplay.h"
#include "../util/random-generation.h"
#include "gamestate-base.h"

class Collectable;

class GameStateGameplay : public GameState
{
  public:
    GameStateGameplay(GameManager* game_manager,
                      Window& game_window,
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
};
