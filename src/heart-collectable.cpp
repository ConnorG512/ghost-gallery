#include "heart-collectable.h"
#include "entity.h"

HeartCollectable::HeartCollectable
(
      const int pos_x, 
      const int pos_y, 
      const std::string& texture_path, 
      const int coll_width, 
      const int coll_height 
) 
  : Entity{ pos_x, pos_y, "assets/image/entity/heart/heart-pickup.png", 128, 128 } {}
