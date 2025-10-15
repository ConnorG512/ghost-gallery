#pragma once

struct HealthComponent {
    HealthComponent( int max_health, int current_health );
    HealthComponent( int max_health );

    int reduceHealth( int health_to_reduce );
    int increaseHealth( int health_to_add );
    void resetHealthToMax();
    
    int max_health { 8 };
    int current_health { max_health };

};
