#pragma once

#include "entity.h"

class HeartCollectable : public Entity
{
  public:
    HeartCollectable
    ( 
      const int pos_x, 
      const int pos_y, 
      const std::string& texture_path, 
      const int coll_width, 
      const int coll_height 
    );

    HeartCollectable
    ( 
      const int pos_x, 
      const int pos_y, 
      const std::string& texture_path, 
      const int coll_width, 
      const int coll_height,
      const int health_to_restore
    );

  protected:
    int m_health_to_restore { 2 };

};
