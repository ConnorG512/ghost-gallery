#pragma once

#include <raylib.h>
#include <utility>

class WindowManager
{
  public:
    WindowManager(int width = 900, int height = 1600, int target_fps = 60);
    ~WindowManager();

    bool ShouldWindowClose();
    void beginDraw();
    void endDraw();
    void drawAndClear();

    [[nodiscard]] std::pair<int, int> GetWindowSize();

    WindowManager(const WindowManager& audio_manager) = delete;                // Delete copy constructor.
    WindowManager& operator=(const WindowManager& audio_manager) = delete;     // Delete copy assignment constructor.
    WindowManager(WindowManager&& audio_manager) noexcept = delete;            // Delete move constructor.
    WindowManager& operator=(WindowManager&& audio_manager) noexcept = delete; // Delete move assignment constructor.

    enum class CursorStatus
    {
        hide,
        show,
    };

    void changeCursorStatus(const CursorStatus status_to_change_to);

  private:
    int m_target_fps{60};
    int m_window_height{1600};
    int m_window_width{900};

    void clearWindow(const Color& colour);
};
