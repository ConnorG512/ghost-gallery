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
    int getCursorX();
    int getCursorY();
    void requestWindowClose();
    
    enum class CursorStatus
    {
      hide,
      show,
    };
    
    void changeCursorStatus( CursorStatus status_to_change_to );
  
  private: 
    int m_width;
    int m_height;
    int m_target_fps;
};
