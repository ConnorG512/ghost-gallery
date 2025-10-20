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

    DrawText(splash_titles.at(0), m_start_position_x, text_y_pos, m_font_size, WHITE);
    text_y_pos += m_spacing;

    DrawText(splash_titles.at(1), m_start_position_x, text_y_pos, m_font_size, WHITE);
    text_y_pos += m_spacing;

    DrawText(std::format("{}: {}", splash_titles.at(2), std::to_string(player_high_score)).c_str(),
             m_start_position_x,
             text_y_pos,
             m_font_size,
             WHITE);
}
