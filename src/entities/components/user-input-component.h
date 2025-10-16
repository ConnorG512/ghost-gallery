#pragma once

namespace InputHandler 
{
  
  enum class ButtonPress 
  {
    none,
    space_key,
    r_key,
    left_mouse
  };
  ButtonPress receiveInput(); 

  int GetMousePosX();
  int GetMousePosY();
}
