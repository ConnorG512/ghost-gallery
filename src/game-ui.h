#pragma once 

class GameUi 
{
  public:
    GameUi( int starting_pos_x = 0, int starting_pos_y = 0, int font_size = 32, int text_spacing = 10 );
    void drawAll();

  private:
    int m_starting_pos_x { 0 };
    int m_starting_pos_y { 0 };
    int m_font_size { 32 };
    int m_text_spacing { 10 };
};
