#pragma once 

#include "../entity.h"

class Collectable : public Entity 
{
  public:
    Collectable
    ( 
      const std::vector<std::string>& texture_paths,
      const int max_health,
      const int current_health,
      const int x_pos,
      const int y_pos,
      const bool is_visible = false 
    );

    void onPlayerHover( Player &player ) override;

  private:
   bool m_is_visible { false };
};
