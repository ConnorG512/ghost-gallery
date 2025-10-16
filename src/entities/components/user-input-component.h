#pragma once

#include <array>
#include <map>
#include <string>

class UserInput
{
  public: 
    enum class InputAction
    {
      none = 0,
      fire = 0,
      start_game = 32,
    };

    InputAction UserAction();
    std::array<int, 2> GetMousePos();

  private:

};
