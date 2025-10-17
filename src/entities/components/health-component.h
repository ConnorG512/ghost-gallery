#pragma once

class HealthComponent 
{
  public:
    HealthComponent( int max_health = 8, int current_health = 8 );
    HealthComponent( int max_health );

    int ReduceHealthBy( int health_to_reduce );
    int IncreaseHealthBy( int health_to_add );
    int SetCurrentHealthTo( int health );
    void resetHealthToMax();
  
  private:
    int m_max_health { 8 };
    int m_current_health { m_max_health };

};
