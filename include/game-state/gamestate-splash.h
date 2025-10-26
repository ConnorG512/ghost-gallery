#pragma once

#include "component/image-sprite.h"
#include "ui/ui-splash.h"
#include "game-state/gamestate-base.h"

class GameStateSplash : public GameState
{
  public:
    GameStateSplash(GameManager* game_manager, Window& game_window, Player& current_player, AudioManager& audio_manger);

    void initialiseState() override;
    void gameplayLoop() override;
    void renderingLoop() override;

  protected:
    void startGameplayLoop();

    ImageSprite m_background_image{{"assets/image/background/manor-1.png"}};
    UiSplash m_ui{10, 10, 40};
};
