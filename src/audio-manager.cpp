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
  SetMasterVolume( 50.0 );
}

AudioManager::~AudioManager()
{
  unloadSounds();
  CloseAudioDevice();
}

void AudioManager::playAudio( const SoundId sound_to_play )
{
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
