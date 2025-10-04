#include "health-component.h"

HealthComponent::HealthComponent( int max_health, int current_health )
  : m_max_health { max_health }, m_current_health { current_health } {}

HealthComponent::HealthComponent( int max_health )
  : m_max_health { max_health } {}

int HealthComponent::reduceHealth( int health_to_reduce ) 
{
  m_current_health -= health_to_reduce; 
  return m_current_health;
}

int HealthComponent::increaseHealth( int health_to_add )
{
  m_current_health += health_to_add;
  if ( m_current_health > m_max_health )
  {
    m_current_health = m_max_health;
  }
  return m_current_health;
}
