#pragma once
#include <raylib.h>

class Window 
{
  public:
    Window( int width, int height, int target_fps );
    ~Window();
    bool shouldWindowClose();
    void beginDraw();
    void endDraw();
    void clearWindow();
  
  private: 
    int m_width;
    int m_height;
    int m_target_fps;
};
