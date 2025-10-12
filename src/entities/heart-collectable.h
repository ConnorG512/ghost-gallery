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
      const bool is_hidden,
      const std::vector<std::string>& texture_paths
    );

    int giveHealth();
    void moveAndActivateToNewLocation();

    EntityType getEntityType() override;
    
  protected:
    int m_health_to_restore { 2 };
    
    void changePosition();
};
