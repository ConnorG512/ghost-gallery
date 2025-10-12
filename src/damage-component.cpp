#include "damage-component.h"
#include "score-manager.h"
#include "random-generation.h"

DamageComponent::DamageComponent() {}

DamageComponent::DamageComponent( const int base_damage, const int critical_chance, const int critical_multiplier )
  : m_base_damage { base_damage }, m_critical_chance { critical_chance }, m_critical_multiplier { critical_multiplier } {}

namespace 
{
  bool HasHitThreshold(const int critical_chance )
  {
    constexpr int max_threshold { 100 };
    constexpr int min_threshold { 1 };

    return RandomGeneration::HasHitThreshold(RandomGeneration::NumberBetween( min_threshold, max_threshold ), critical_chance );
  }
}

int DamageComponent::CalculateDamage()
{
  if ( HasHitThreshold( m_critical_chance ))
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
  if ( score_component.current_score > 2200 ) 
  {
    return CalculateDamage(m_critical_chance *= 4, m_critical_multiplier *= 3);
  }
  else if ( score_component.current_score > 1750 )
  {
    return CalculateDamage(m_critical_chance *= 3, m_critical_multiplier *= 2);
  }
  else if ( score_component.current_score > 1200 )
  {
    return CalculateDamage(m_critical_chance *= 2, m_critical_multiplier *= 1);
  }
  else 
  {
    return CalculateDamage();
  }
}

int DamageComponent::CalculateDamage( const int critical_chance, const int critical_multiplier )
{
  if ( HasHitThreshold( critical_chance ))
  {
    return m_base_damage * critical_multiplier;
  }
  else 
  {
    return m_base_damage;
  }
}
