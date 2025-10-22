#pragma once

#include <raylib.h>
#include <string>
#include <vector>

class AudioManager
{
  public:
    AudioManager();
    ~AudioManager();

    AudioManager(const AudioManager& audio_manager) = delete;                // Delete copy constructor.
    AudioManager& operator=(const AudioManager& audio_manager) = delete;     // Delete copy assignment constructor.
    AudioManager(AudioManager&& audio_manager) noexcept = delete;            // Delete move constructor.
    AudioManager& operator=(AudioManager&& audio_manager) noexcept = delete; // Delete move assignment constructor.

    enum class SoundId
    {
        ghost_death,
        heart_pickup,
        coin_pickup,
        candy_pickup,
    };
    void playAudio(const SoundId sound_to_play);

  private:
    std::vector<Sound> m_loaded_sounds;

    void loadSounds();
    void unloadSounds();
};
