#include "tick-component.h"

TickComponent::TickComponent(const int maximum_tick, const int tick_rate)
    : m_maximum_tick{maximum_tick}, m_tick_rate{tick_rate}
{
}

bool TickComponent::HasHitTickThreshold()
{
    if (m_current_tick != 0)
    {
        if (m_current_tick % m_maximum_tick == 0)
        {
            resetTickCount();
            return true;
        }
    }
    return false;
}

void TickComponent::incrementTickCount() { m_current_tick += m_tick_rate; }

void TickComponent::resetTickCount() { m_current_tick = 0; }

bool TickComponent::IncrementAndCheckThreshold()
{
    incrementTickCount();
    return HasHitTickThreshold();
}

void TickComponent::setNewTickThreshold(const int new_tick) { m_maximum_tick = new_tick; }
