#include "include/entity/player.h"
#include "include/manager/audio-manager.h"
#include "include/entity/entity.h"

#include <utility>

namespace
{
constexpr int cursor_offset{64};
}

Player::Player(const int x_pos, const int y_pos)
    : Entity{{"assets/image/ui/cursor-target.png",
              "assets/image/ui/cursor-target-found.png",
              "assets/image/ui/cursor-target-found-friendly.png"},
             8,
             8,
             x_pos,
             y_pos}
{
}

void Player::ResetPlayerStats()
{
    health_component.resetHealthToMax();
    score_component.resetScore();
}

void Player::drawPlayerCursor()
{
    sprite.drawSprite({user_input.GetMousePos().at(0), user_input.GetMousePos().at(1)},
                      std::to_underlying(m_current_cursor_state));
    collision.updateCollisionPosition(user_input.GetMousePos());
}

void Player::changeCursorState(const CursorType cursor_type_to_change)
{
    m_current_cursor_state = cursor_type_to_change;
}

void Player::takeDamage(const int damage_amount, AudioManager& audio_manager)
{
    if (damage_amount <= 0)
    {
        return;
    };
    health_component.ReduceHealthBy(damage_amount);
    audio_manager.playAudio(AudioManager::SoundId::player_hurt);
}
