#pragma once

#include "../image-sprite.h"
#include "../ui/ui-splash.h"
#include "gamestate-base.h"

class GameStateSplash : public GameState
{
  public:
    GameStateSplash(GameManager *game_manager, Window &game_window,
                    Player &current_player, AudioManager &audio_manger);

    void initialiseState() override;
    void inputLoop() override;
    void gameplayLoop() override;

  protected:
    void startGameplayLoop();

    ImageSprite m_background_image{{"assets/image/background/manor-1.png"}};
    UiSplash m_ui{10, 10, 40};
};
