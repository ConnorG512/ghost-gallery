#include "audio-manager.h"

#include <array>
#include <raylib.h>
#include <vector>

namespace
{
constexpr float master_volume_increment{0.1f};
}

AudioManager::AudioManager()
{
    InitAudioDevice();
    loadSounds();
    SetMasterVolume(m_master_volume);
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
        case AudioManager::SoundId::player_hurt:
            PlaySound(m_loaded_sounds.at(4));
    }
}

void AudioManager::loadSounds()
{
    constexpr std::array<const char*, 6> sound_files{
        "assets/audio/pepSound1.ogg",
        "assets/audio/powerUp2.ogg",
        "assets/audio/powerUp11.ogg",
        "assets/audio/powerUp8.ogg",
        "assets/audio/twoTone1.ogg",
        "assets/audio/zapTwoTone2.ogg",
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

void AudioManager::increaseMasterVolumeBy()
{
    if (m_master_volume >= 1.0)
    {
        m_master_volume = 1.0;
    }
    m_master_volume += master_volume_increment;

    SetMasterVolume(m_master_volume);
}

void AudioManager::decreaseMasterVolumeBy()
{
    if (m_master_volume <= 0.0)
    {
        m_master_volume = 0.0;
    }
    m_master_volume -= master_volume_increment;

    SetMasterVolume(m_master_volume);
}
