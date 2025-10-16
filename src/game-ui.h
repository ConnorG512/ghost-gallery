#pragma once 

#include <vector>
#include <string>

class Player;
class ScoreManager;

class GameUi 
{
  public:
    GameUi( const int starting_pos_x = 0, const int starting_pos_y = 0, const int font_size = 32, const int text_spacing = 40 );
    void drawAll( const std::array<int, 3>& game_props );

  private:
    int m_starting_pos_x { 0 };
    int m_starting_pos_y { 0 };
    int m_font_size { 32 };
    int m_text_spacing { 40 };
};
