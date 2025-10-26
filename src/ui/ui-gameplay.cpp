#include "ui/ui-gameplay.h"

#include <algorithm>
#include <array>
#include <format>
#include <ranges>
#include <raylib.h>

UiGameplay::UiGameplay(const int start_pos_x, const int start_pos_y, const int spacing, const int font_size)
    : Ui{start_pos_x, start_pos_y, spacing, font_size}
{
}

void UiGameplay::drawUi(const std::array<int, 3>& player_stats)
{
    constexpr std::array<const char*, 3> ui_strings{
        "Score",
        "Health",
        "Multiplier",
    };

    int text_y_pos{m_start_position_y};
    std::ranges::for_each(
        std::views::zip(ui_strings, player_stats),
        [this, &text_y_pos](auto const& pair)
        {
            const auto& [string, stat] = pair;
            DrawText(std::format("{}: {}", string, stat).c_str(), m_start_position_x, text_y_pos, m_font_size, WHITE);
            text_y_pos += m_spacing;
        });
}
