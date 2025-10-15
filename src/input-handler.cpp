#include "input-handler.h"

#include <raylib.h>

InputHandler::ButtonPress InputHandler::receiveInput()
{
  if ( IsMouseButtonPressed( MOUSE_BUTTON_LEFT ))
  {
    return InputHandler::ButtonPress::left_mouse;
  }
  else if ( IsKeyPressed( KEY_SPACE ))
  {
    return InputHandler::ButtonPress::space_key;
  }
  else if ( IsKeyPressed( KEY_R ))
  {
    return InputHandler::ButtonPress::r_key;
  }
  else 
  { 
    return InputHandler::ButtonPress::none; 
  }
}

int GetMousePosX()
{
  return GetMouseX();
}

int GetMousePosY()
{
  return GetMouseY();
}
