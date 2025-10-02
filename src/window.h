#pragma once

class Window 
{
  public:
    Window();
    ~Window();
    bool shouldWindowClose();
    void beginDraw();
    void endDraw();
    void clearWindow();
  
  private: 
    int m_length;
    int m_width;
    int m_target_fps;
};
