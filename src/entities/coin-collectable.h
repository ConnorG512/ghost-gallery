#pragma once

#include "entity.h"
#include <string>
#include <vector>

class ScoreManager;

class CoinCollectable : public Entity
{
  public:
    CoinCollectable( const int pos_x, const int pos_y, const bool is_hidden, const std::vector<std::string>& texture_paths );
    int GivePoints( ScoreManager& score_manager );
    
    void respawnToNewLocation();

    EntityType getEntityType() override;

  private:
    void increaseScoreMultiplier( ScoreManager& score_manager );
};
