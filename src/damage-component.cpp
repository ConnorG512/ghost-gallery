#include "damage-component.h"
#include "score-manager.h"
#include "random-generation.h"
#include <array>

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
  constexpr std::array<int, 6> enemy_damage { 6, 5, 4, 3, 2, 1 }; 

  for ( int index = 0; index < score_component.score_thresholds.size(); ++index )
  {
    if ( score_component.current_score > score_component.score_thresholds[ index ])
    {
      return enemy_damage[ index ];
    }
  }
  return enemy_damage[ 5 ]; 
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
