#include "collectable.h"

Collectable::Collectable(const std::vector<std::string> &texture_paths,
                         const int max_health, const int current_health,
                         const int x_pos, const int y_pos,
                         const bool is_visible)
    : Entity{texture_paths, max_health, current_health, x_pos, y_pos},
      m_is_visible{is_visible} {}
