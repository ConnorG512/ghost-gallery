#include <raylib.h>

class Window 
{
  public: 
    Window(int length, int width, int target_fps) 
      : m_length { length }
      , m_width { width }
      , m_target_fps { target_fps }
    {
      InitWindow(m_width, m_length, "app");
      SetTargetFPS(m_target_fps);
    }
    ~Window() 
    {
      CloseWindow();
    }

    bool shouldWindowClose() 
    {
      return WindowShouldClose();
    }

    void beginDraw()
    {
      BeginDrawing();
    }
    
    void endDraw()
    {
      EndDrawing();
    }
    
    void clearWindow()
    {
      ClearBackground(YELLOW);
    }

  private:
    int m_length { 600 };
    int m_width { 800 };
    int m_target_fps { 60 };
};
