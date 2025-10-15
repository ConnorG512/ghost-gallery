#include "spawn-manager.h"
#include "random-generation.h"

SpawnManager::SpawnManager( int num_spawn_slots )
  : m_spawn_slots { num_spawn_slots } {}

namespace 
{
  constexpr std::array<int, 2> collectable_spawn_threshold_x { 200, 1400 };
  constexpr std::array<int, 2> collectable_spawn_threshold_y { 100, 700 };
}

SpawnManager::~SpawnManager()
{
  unloadManager();
}

void SpawnManager::drawCollectables()
{
  for ( auto*& collectable_slot : m_collectables_list )
  {
    if (collectable_slot != nullptr )
    {
      collectable_slot->sprite.drawSprite();
    }
  }
}

void SpawnManager::requestCollectable()
{
  for ( auto*& collectable_slot : m_collectables_list )
  {
    if ( collectable_slot == nullptr )
    {
      collectable_slot = createCollectable();
      break;
    }
  }
}

Collectable* SpawnManager::createCollectable()
{
  if ( !isManagerFull())
  {
    if ( RandomGeneration::HasHitThreshold(RandomGeneration::NumberBetween(), 50 ))
    {
      if ( RandomGeneration::HasHitThreshold(RandomGeneration::NumberBetween(), 50 ))
      {
        return createCoinCollectable();
      }
      else 
      {
        return createHeartCollectable();
      }
    }
  }

  return nullptr;
}

bool SpawnManager::isManagerFull()
{
  return m_collectables_list.size() >= m_spawn_slots;
}

Collectable* SpawnManager::createCoinCollectable()
{
  return new Collectable 
  {
    { 
      "assets/image/entity/coin/coin.png" 
    },
    1,
    1,
    RandomGeneration::NumberBetween
    (
      collectable_spawn_threshold_x.at( 0 ),
      collectable_spawn_threshold_x.at( 1 )
    ),
    RandomGeneration::NumberBetween
    (
      collectable_spawn_threshold_y.at( 0 ),
      collectable_spawn_threshold_y.at( 1 )
    ),
  };
}

Collectable* SpawnManager::createHeartCollectable()
{
  return new Collectable
  {
    {
      "assets/image/entity/heart/heart-pickup.png"
    },
    1,
    1,
    RandomGeneration::NumberBetween
    (
      collectable_spawn_threshold_x.at( 0 ),
      collectable_spawn_threshold_x.at( 1 )
    ),
    RandomGeneration::NumberBetween
    (
      collectable_spawn_threshold_y.at( 0 ),
      collectable_spawn_threshold_y.at( 1 )
    ),
  };
}

void SpawnManager::unloadManager()
{
  for ( auto*& collectable_slot : m_collectables_list )
  {
    if ( collectable_slot != nullptr )
    {
      delete collectable_slot;
      collectable_slot = nullptr;
    }
  }
}
