#pragma once 

#include "gamestate-base.h"
#include "../image-sprite.h"

class GameStateSplash : public GameState 
{
  public:
    GameStateSplash(GameManager* game_manager, Window& game_window, ScoreManager& score_manager, AudioManager& audio_manger );
    
    void initialiseState() override;
    void inputLoop() override;
    void gameplayLoop() override;

  protected:
    void startGameplayLoop();
    void drawSplashText();

    ImageSprite m_background_image { { "assets/image/background/manor-1.png" }, 0, 0 };
};
