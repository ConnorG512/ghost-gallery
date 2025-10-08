#pragma once

class HealthComponent {
  public:
    HealthComponent( int max_health, int current_health );
    HealthComponent( int max_health );

    int reduceHealth( int health_to_reduce );
    int increaseHealth( int health_to_add );
    void resetHealthToMax();
    
    int m_current_health { m_max_health };

  private:
    int m_max_health { 8 };
};
