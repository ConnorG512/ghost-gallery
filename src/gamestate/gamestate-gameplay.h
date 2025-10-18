#pragma once

#include "../entities/enemy.h"
#include "../entities/player.h"
#include "../image-sprite.h"
#include "../random-generation.h"
#include "../spawner/spawn-manager-collectable.h"
#include "../ui/ui-gameplay.h"
#include "gamestate-base.h"

class Collectable;

class GameStateGameplay : public GameState
{
  public:
    GameStateGameplay(GameManager *game_manager, Window &game_window,
                      Player &current_player, AudioManager &audio_manager);
    ~GameStateGameplay() = default;

    void initialiseState() override;
    void inputLoop() override;
    void gameplayLoop() override;

  protected:
    ImageSprite m_background_image{{"assets/image/background/manor-1.png"}};
    SpawnManager m_collectable_spawn_manager{};
    Enemy m_enemy{
        RandomGeneration::NumberBetween(100, 1500),
        RandomGeneration::NumberBetween(100, 600),
    };
    UiGameplay m_ui{10, 10, 40};

    void onGameTicks();
    void gameOver();
};
