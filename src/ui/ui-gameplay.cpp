#include "ui-gameplay.h"
#include <array>
#include <format>
#include <raylib.h>

UiGameplay::UiGameplay(const int start_pos_x, const int start_pos_y,
                       const int spacing, const int font_size)
    : Ui{start_pos_x, start_pos_y, spacing, font_size}
{
}

void UiGameplay::drawUi(const std::array<int, 3> &player_stats)
{

    constexpr std::array<const char *, 3> ui_strings{
        "Score",
        "Health",
        "Multiplier",
    };

    int text_y_pos{m_start_position_y};
    for (int i = 0; i < ui_strings.size(); ++i)
    {
        DrawText(
            std::format("{}: {}", ui_strings.at(i), player_stats.at(i)).c_str(),
            m_start_position_x, text_y_pos, m_font_size, WHITE);
        text_y_pos += m_spacing;
    }
}
