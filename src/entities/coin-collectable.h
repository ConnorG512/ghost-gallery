#pragma once
#include "entity.h"
#include <string>
#include <vector>

class ScoreManager;

class CoinCollectable : public Entity
{
  public:
    CoinCollectable( const int pos_x, const int pos_y, const std::vector<std::string>& texture_paths );
    int GivePoints( ScoreManager& score_manager );
};
