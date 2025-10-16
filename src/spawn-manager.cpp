#include "spawn-manager.h"
#include "audio-manager.h"
#include "entities/components/user-input-component.h"
#include "random-generation.h"
#include "entities/collectable/heart-collectable.h"
#include "entities/collectable/coin-collectable.h"
#include "entities/player.h"
#include "audio-manager.h"

SpawnManager::SpawnManager( int num_spawn_slots )
  : m_spawn_slots { num_spawn_slots } 
{
  allocateSlots();
}

namespace 
{
  constexpr std::array<int, 2> collectable_spawn_threshold_x { 200, 1400 };
  constexpr std::array<int, 2> collectable_spawn_threshold_y { 100, 700 };
}

SpawnManager::~SpawnManager()
{
  unloadManager();
}

void SpawnManager::allocateSlots()
{
  for (int i = 0; i < m_spawn_slots; ++i )
  {
    m_collectables_list.push_back( nullptr );
  }
}

void SpawnManager::drawCollectables()
{
  for ( auto*& collectable_slot : m_collectables_list )
  {
    if ( collectable_slot != nullptr )
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
  int result = RandomGeneration::NumberBetween(0, 1); 
  if ( result == 1 )
  {
    return createCoinCollectable();
  }
  else 
  {
    return createHeartCollectable();
  }
}

CoinCollectable* SpawnManager::createCoinCollectable()
{
  return new CoinCollectable 
  {
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

HeartCollectable* SpawnManager::createHeartCollectable()
{
  return new HeartCollectable
  {
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
    delete collectable_slot;
    collectable_slot = nullptr;
  }
}

void SpawnManager::checkForPlayerInteraction( Player& current_player, AudioManager& audio_manager )
{
  for ( auto*& collectable_slot : m_collectables_list )
  {
    if ( collectable_slot != nullptr && collectable_slot->collision.isCollidingWith( current_player.collision.m_collision_shape ))
    {
      current_player.drawPlayerCursor( Player::CursorType::friendly );
      
      using enum UserInput::InputAction;
      if ( current_player.user_input.UserAction() == fire )
      {
        collectable_slot->givePoweUp( current_player );
        collectable_slot->playSound( audio_manager );

        delete collectable_slot;
        collectable_slot = nullptr;
      }
    };
  }
}

bool SpawnManager::isSpawnerReady()
{
  m_tick_component.incrementTickCount();
  return m_tick_component.hasHitTickThreshold();
}
