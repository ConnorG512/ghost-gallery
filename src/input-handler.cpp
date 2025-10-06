#include "input-handler.h"

#include <raylib.h>

bool InputHandler::leftMousePressed()
{
  return IsMouseButtonPressed( MOUSE_BUTTON_LEFT );
}
