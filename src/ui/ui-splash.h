#pragma once 

#include "ui.h"

class UiSplash : public Ui 
{
  public:
  UiSplash( const int start_pos_x, const int start_pos_y, const int spacing, const int font_size = 32 );  
  
  void drawUi();
};
