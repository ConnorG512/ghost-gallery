#include "damage-component.h"

DamageComponent::DamageComponent() {}

DamageComponent::DamageComponent
( 
 const int base_damage, 
 const int critical_chance, 
 const int critical_multiplier 
)
  : m_base_damage { base_damage }, m_critical_chance { critical_chance }, m_critical_multiplier { critical_multiplier } {}

namespace { }

