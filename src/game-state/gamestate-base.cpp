#include "game-state/gamestate-base.h"

GameState::GameState(GameManager* game_manager,
                     WindowManager& game_window,
                     Player& current_player,
                     AudioManager& audio_manger)
    : m_game_window{game_window}, m_game_manager{game_manager}, m_current_player{current_player},
      m_audio_manager{audio_manger}
{
}
