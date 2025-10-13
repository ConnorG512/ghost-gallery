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
    };
    void playAudio( const SoundId sound_to_play );

  private:
    std::vector<Sound> m_loaded_sounds; 

    void loadSounds();
    void unloadSounds();
};
