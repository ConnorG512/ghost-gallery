#include "spawn-manager.h"

SpawnManager::SpawnManager(const int tick_threshold, const int num_spawn_slots)
    : m_ticker{tick_threshold}, m_num_available_slots{num_spawn_slots}
{
}

void SpawnManager::setNewSpawnSlotsNum(const int slots)
{
    m_num_available_slots = slots;
}
