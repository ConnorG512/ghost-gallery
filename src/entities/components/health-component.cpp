#include "include/component/health-component.h"

HealthComponent::HealthComponent(int max_health, int current_health)
    : m_max_health{max_health}, m_current_health{current_health}
{
}

HealthComponent::HealthComponent(int max_health) : m_max_health{max_health} {}

int HealthComponent::ReduceHealthBy(const int health_to_reduce)
{
    m_current_health -= health_to_reduce;
    if (m_current_health <= 0)
    {
        m_current_health = 0;
    }
    return m_current_health;
}

int HealthComponent::IncreaseHealthBy(const int health_to_add)
{
    m_current_health += health_to_add;
    if (m_current_health > m_max_health)
    {
        m_current_health = m_max_health;
    }
    return m_current_health;
}

int HealthComponent::SetCurrentHealthTo(const int health)
{
    m_current_health = health;
    if (m_current_health > m_max_health)
    {
        m_current_health = m_max_health;
    }
    return m_current_health;
}

void HealthComponent::resetHealthToMax() { m_current_health = m_max_health; }

int& HealthComponent::GetHealth() { return m_current_health; }
