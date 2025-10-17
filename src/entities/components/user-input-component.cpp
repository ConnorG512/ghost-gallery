#include "user-input-component.h"

#include <raylib.h>

UserInput::InputAction UserInput::UserAction() {
  using enum UserInput::InputAction;
  if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    return fire;
  } else if (GetKeyPressed() == KEY_SPACE) {
    return start_game;
  } else {
    return none;
  }
}

std::array<int, 2> UserInput::GetMousePos() {
  return {GetMouseX(), GetMouseY()};
}
