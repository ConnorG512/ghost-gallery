#include "gamestate-gameplay.h"
#include "gamestate-base.h"
#include "../text-render.h"

GameStateGameplay::GameStateGameplay( Window& game_window )
  : GameState { game_window } {};

void GameStateGameplay::inputLoop()
{
  // TODO
}

void GameStateGameplay::gameplayLoop()
{
  m_game_window.beginDraw();
  m_game_window.clearWindow();
  TextRender::drawTextToScreen( "GAMEPLAY", 900, 500, 32 ); 
  m_game_window.endDraw();
}
