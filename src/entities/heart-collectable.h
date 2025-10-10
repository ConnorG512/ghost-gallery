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
    int giveHealth();

    bool is_active { false };
  
  protected:
    int m_health_to_restore { 2 };
};
