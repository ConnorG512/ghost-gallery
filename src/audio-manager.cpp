#include "audio-manager.h"
#include <raylib.h>
#include <vector>

namespace 
{
}

AudioManager::AudioManager()
{
  InitAudioDevice(); 
  loadSounds();
  SetMasterVolume( 25.0 );
}

AudioManager::~AudioManager()
{
  unloadSounds();
  CloseAudioDevice();
}

void AudioManager::playAudio( const SoundId sound_to_play )
{
  switch ( sound_to_play ) 
  {
    case AudioManager::SoundId::ghost_death:
      PlaySound(m_loaded_sounds.at( 0 ));
  }
}

void AudioManager::loadSounds()
{
    m_loaded_sounds.push_back( LoadSound( "assets/audio/pepSound1.ogg" ));
}

void AudioManager::unloadSounds()
{
  for ( Sound current_loaded_sound : m_loaded_sounds )
  {
    UnloadSound( current_loaded_sound );
  }
}
