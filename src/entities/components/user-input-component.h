#pragma once

#include <array>
#include <map>
#include <string>

class AudioManager;

class UserInput
{
  public:
    enum class InputAction
    {
        none,
        fire,
        start_game,
    };

    [[nodiscard]] InputAction UserAction();
    [[nodiscard]] std::array<int, 2> GetMousePos();
    void increaseVolume(AudioManager& audio_manager);
    void decreaseVolume(AudioManager& audio_manager);

  private:
};
