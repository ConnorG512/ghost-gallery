#pragma once

#include "components/damage-component.h"
#include "components/health-component.h"
#include "components/score-component.h"
#include "components/user-input-component.h"
#include "entity.h"

class Window;
class ScoreComponent;

class Player : public Entity
{
  public:
    Player(const int x_pos = 0, const int y_pos = 0);
    ScoreComponent score_component{};
    UserInput user_input{};

    void ResetPlayerStats();

    enum class CursorType
    {
        neutral = 0,
        enemy = 1,
        friendly = 2,
    };

    void drawPlayerCursor();
    void drawPlayerCursor(const CursorType cursor_to_change_to);
};
