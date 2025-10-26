#include "include/manager/spawn-manager.h"

SpawnManager::SpawnManager(const int num_spawn_slots) : m_num_available_slots{num_spawn_slots} {}

void SpawnManager::setNewSpawnSlotsNum(const int slots) { m_num_available_slots = slots; }
