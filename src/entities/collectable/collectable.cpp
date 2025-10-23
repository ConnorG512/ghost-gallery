#include "collectable.h"

Collectable::Collectable(const std::vector<std::string>& texture_paths, const int x_pos, const int y_pos)
    : Entity{texture_paths, 1, 1, x_pos, y_pos}
{
}
