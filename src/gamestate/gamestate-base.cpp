#include "gamestate-base.h"

GameState::GameState( GameManager* game_manager, Window& game_window )
  : m_game_window { game_window }
  , m_game_manager { game_manager }{}

GameState::~GameState() = default;
