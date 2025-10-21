#include "candy-collectable.h"
#include "collectable.h"

CandyCollectable::CandyCollectable(const int x_pos, const int y_pos, const int multiplier_amount)
    : Collectable({"assets/image/entity/candy"}, 2, 2, x_pos, y_pos, true), m_multiplier_to_give{multiplier_amount}
{
}
