#include "gamestate-base.h"

GameState::GameState( Window& game_window )
  : m_game_window { game_window } {}

GameState::~GameState() = default;
