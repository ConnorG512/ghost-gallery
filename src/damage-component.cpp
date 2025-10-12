#include "damage-component.h"
#include "score-manager.h"
#include "random-generation.h"

DamageComponent::DamageComponent() {}

DamageComponent::DamageComponent( const int base_damage, const int critical_chance, const int critical_multiplier )
  : m_base_damage { base_damage }, m_critical_chance { critical_chance }, m_critical_multiplier { critical_multiplier } {}

int DamageComponent::CalculateDamage()
{
  if ( RandomGeneration::HasHitThreshold(RandomGeneration::NumberBetween(1, 100), m_critical_chance))
  {
    return m_base_damage * m_critical_multiplier;
  }
  else 
  {
    return m_base_damage;
  }
}

int DamageComponent::CalculateDamage( const ScoreManager& score_component )
{
  if ( score_component.current_score > 500 )
  {
    m_critical_chance *= 2;
    return CalculateDamage();
  }
  else if ( score_component.current_score > 1200 )
  {
    m_critical_chance *= 2;
    return CalculateDamage();
  }
  else if ( score_component.current_score > 1750 )
  {
    m_critical_chance *= 3;
    m_critical_multiplier *= 2;
    return CalculateDamage();
  }
  else if ( score_component.current_score > 2200 ) 
  {
    m_critical_chance *= 4;
    m_critical_multiplier *= 3;
    return CalculateDamage();
  }
  else 
  {
    return CalculateDamage();
  }
}
