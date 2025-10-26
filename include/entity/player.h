#pragma once

#include "component/score-component.h"
#include "component/user-input-component.h"
#include "entity/entity.h"

class ScoreComponent;

class Player : public Entity
{
  public:
    Player(const int x_pos = 0, const int y_pos = 0);
    ScoreComponent score_component{};
    UserInput user_input{};

    void ResetPlayerStats();
    void drawPlayerCursor();
    void takeDamage(const int damage_amount, AudioManager& audio_manager);

    enum class CursorType
    {
        neutral = 0,
        enemy = 1,
        friendly = 2,
    };
    void changeCursorState(const CursorType cursor_type_to_change);

  private:
    CursorType m_current_cursor_state{CursorType::neutral};
};
