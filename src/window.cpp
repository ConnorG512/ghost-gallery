#include "window.h"
#include <raylib.h>

Window::Window(int width, int height, int target_fps) 
  : m_width { width }
  , m_height { height }
  , m_target_fps { target_fps }
{
  InitWindow(m_width, m_height, "app");
  SetTargetFPS(m_target_fps);
}

Window::~Window() 
{
  CloseWindow();
}

bool Window::shouldWindowClose() 
{
  return WindowShouldClose();
}

void Window::beginDraw()
{
  BeginDrawing();
}

void Window::endDraw()
{
  EndDrawing();
}

void Window::clearWindow()
{
  ClearBackground(YELLOW);
}

int Window::getCursorX()
{
  return GetMouseX();
}

int Window::getCursorY()
{
  return GetMouseY();
}

void Window::changeCursorStatus( CursorStatus status_to_change_to )
{
  switch ( status_to_change_to ) 
  {
    case CursorStatus::hide:
      HideCursor();
      break;
    case CursorStatus::show:
      ShowCursor();
      break;
  }
}
