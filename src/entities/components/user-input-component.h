#pragma once

#include <array>
#include <map>
#include <string>

class UserInput
{
  public:
    enum class InputAction
    {
        none,
        fire,
        start_game,
    };

    InputAction UserAction();
    std::array<int, 2> GetMousePos();

  private:
};
