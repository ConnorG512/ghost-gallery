#include "window.h"
#include <raylib.h>

Window::Window(int width, int height, int target_fps)
    : m_window_width{width}, m_window_height{height}, m_target_fps{target_fps} {
  InitWindow(m_window_width, m_window_height, "Ghost Gallery");
  SetTargetFPS(m_target_fps);
}

Window::~Window() { CloseWindow(); }

bool Window::ShouldWindowClose() { return WindowShouldClose(); }

void Window::beginDraw() { BeginDrawing(); }

void Window::endDraw() { EndDrawing(); }

void Window::clearWindow(const Color &colour) { ClearBackground(colour); }

void Window::drawAndClear() {
  beginDraw();
  constexpr Color default_window_colour{0, 0, 0, 0};
  clearWindow(default_window_colour);
}

void Window::changeCursorStatus(const CursorStatus status_to_change_to) {
  switch (status_to_change_to) {
  case CursorStatus::hide:
    HideCursor();
    break;
  case CursorStatus::show:
    ShowCursor();
    break;
  }
}
