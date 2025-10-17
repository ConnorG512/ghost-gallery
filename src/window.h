#pragma once
#include <raylib.h>

class Window 
{
  public:
    Window( int width = 900, int height = 1600, int target_fps = 60 );
    ~Window();
    bool ShouldWindowClose();
    void beginDraw();
    void endDraw();
    void drawAndClear();
    
    enum class CursorStatus
    {
      hide,
      show,
    };
    
    void changeCursorStatus( const CursorStatus status_to_change_to );
  
  private: 
    int m_target_fps { 60 };
    int m_window_height { 1600 };
    int m_window_width { 900 };
    
    void clearWindow( const Color& colour );
};
