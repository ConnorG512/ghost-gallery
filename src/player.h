#pragma once

#include "entity.h"
#include "health-component.h"

#include <raylib.h>

class Player : public Entity
{
  public:
    Player( const int pos_x, const int pos_y, const std::string& texture_path, const int coll_width, const int coll_height );

    int addToScore(int score_to_add);

    int m_current_score { 0 };

  private:
};
