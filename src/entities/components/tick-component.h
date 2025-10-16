#pragma once

class TickComponent
{
  public:

    TickComponent( const int maximum_tick = 60, const int tick_rate = 1 );
    
    bool hasHitTickThreshold();
    void incrementTickCount();
    void resetTickCount();
  
  private:
    int m_maximum_tick { 60 };
    int m_tick_rate { 1 };
    int m_current_tick { 0 };
};
