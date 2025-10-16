#include "user-input-component.h"

#include <raylib.h>
#include <utility>

UserInput::InputAction UserInput::UserAction()
{
  using enum UserInput::InputAction;
  if ( IsMouseButtonPressed( std::to_underlying( InputAction::fire )))
  {
    return fire;
  }
  else if ( IsKeyPressed( std::to_underlying(InputAction::start_game )))
  {
    return start_game;
  }
  return none;
}

std::array<int, 2> UserInput::GetMousePos()
{
  return { GetMouseX(), GetMouseY() };
}
