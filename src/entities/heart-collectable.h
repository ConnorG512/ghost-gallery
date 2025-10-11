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
    bool isHeartActive();
    void deactivatePickup();

    void moveAndActivateToNewLocation();

  
  protected:
    bool m_is_active { false };
    int m_health_to_restore { 2 };
    
    void changePosition();
};
