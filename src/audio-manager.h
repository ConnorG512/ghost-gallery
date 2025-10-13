#pragma once 

#include <raylib.h>
#include <vector>
#include <string>

class AudioManager 
{
  public:
    AudioManager();
    ~AudioManager();

    enum class SoundId 
    {
      ghost_death,
      heart_pickup,
      coin_pickup,
    };
    void playAudio( const SoundId sound_to_play );

  private:
    std::vector<Sound> m_loaded_sounds; 

    void loadSounds();
    void unloadSounds();
};
