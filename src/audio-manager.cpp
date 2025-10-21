#include "audio-manager.h"
#include <array>
#include <raylib.h>
#include <vector>

namespace
{
}

AudioManager::AudioManager()
{
    InitAudioDevice();
    loadSounds();
    SetMasterVolume(25.0);
}

AudioManager::~AudioManager()
{
    unloadSounds();
    CloseAudioDevice();
}

void AudioManager::playAudio(const SoundId sound_to_play)
{
    switch (sound_to_play)
    {
        case AudioManager::SoundId::ghost_death:
            PlaySound(m_loaded_sounds.at(0));
            break;
        case AudioManager::SoundId::heart_pickup:
            PlaySound(m_loaded_sounds.at(1));
            break;
        case AudioManager::SoundId::coin_pickup:
            PlaySound(m_loaded_sounds.at(2));
            break;
        case AudioManager::SoundId::candy_pickup:
            PlaySound(m_loaded_sounds.at(3));
    }
}

void AudioManager::loadSounds()
{
    constexpr std::array<const char*, 4> sound_files{
        "assets/audio/pepSound1.ogg",
        "assets/audio/powerUp2.ogg",
        "assets/audio/powerUp11.ogg",
        "assets/audio/powerUp8.ogg",
    };

    for (const char* file_path : sound_files)
    {
        m_loaded_sounds.push_back(LoadSound(file_path));
    }
}

void AudioManager::unloadSounds()
{
    for (Sound current_loaded_sound : m_loaded_sounds)
    {
        UnloadSound(current_loaded_sound);
    }
}
