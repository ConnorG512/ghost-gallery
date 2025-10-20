#include "damage-component.h"
#include "../../util/random-generation.h"

DamageComponent::DamageComponent() {}

DamageComponent::DamageComponent(const int base_damage, const int critical_chance, const int critical_multiplier)
    : m_base_damage{base_damage}, m_critical_chance{critical_chance}, m_critical_multiplier{critical_multiplier}
{
}

int DamageComponent::CalculateDamage()
{
    if (RandomGeneration::HasHitRandomNumberThreshold(m_critical_chance))
    {
        return m_base_damage * m_critical_multiplier;
    }
    return m_base_damage;
}
