#pragma once

#include "entity.h"

#include <vector>

class HeartCollectable : public Entity
{
  public:
    HeartCollectable
    ( 
      const int pos_x, 
      const int pos_y, 
      const std::vector<std::string>& texture_paths
    );

    void drawToScreen();
    void drawToScreen( int x_pos, int y_pos );
    int giveHealth();
    void changePosition();

    bool is_active { false };
  
  protected:
    int m_health_to_restore { 2 };
};
