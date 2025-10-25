#include "ui-splash.h"
#include <format>
#include <raylib.h>
#include <string>

UiSplash::UiSplash(const int start_pos_x, const int start_pos_y, const int spacing, const int font_size)
    : Ui{start_pos_x, start_pos_y, spacing, font_size}
{
}

void UiSplash::drawUi(const int& player_high_score)
{
    constexpr std::array<const char*, 3> splash_titles{
        "Press space to start...",
        "Press escape to exit...",
        "Current high score",
    };

    int text_y_pos{m_start_position_y};

    for (auto const current_string : splash_titles)
    {
        DrawText(current_string, m_start_position_x, text_y_pos, m_font_size, WHITE);
        text_y_pos += m_spacing;
    }
}
