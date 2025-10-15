#include "health-component.h"

HealthComponent::HealthComponent( int max_health, int current_health )
  : max_health { max_health }, current_health { current_health } {}

HealthComponent::HealthComponent( int max_health )
  : max_health { max_health } {}

int HealthComponent::reduceHealth( int health_to_reduce ) 
{
  current_health -= health_to_reduce; 
  if ( current_health <= 0 )
  {
    current_health = 0;
  }
  return current_health;
}

int HealthComponent::increaseHealth( int health_to_add )
{
  current_health += health_to_add;
  if ( current_health > max_health )
  {
    current_health = max_health;
  }
  return current_health;
}

void HealthComponent::resetHealthToMax()
{
  current_health = max_health;
}
