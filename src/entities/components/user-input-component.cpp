#include "user-input-component.h"
#include "../../audio-manager.h"

#include <raylib.h>

UserInput::InputAction UserInput::UserAction()
{
    using enum UserInput::InputAction;
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        return fire;
    }
    else if (GetKeyPressed() == KEY_SPACE)
    {
        return start_game;
    }
    else
    {
        return none;
    }
}

std::array<int, 2> UserInput::GetMousePos() { return {GetMouseX(), GetMouseY()}; }

void UserInput::increaseVolume(AudioManager& audio_manager)
{
    if (IsKeyPressed(KEY_P))
    {
        audio_manager.increaseMasterVolume();
    }
}

void UserInput::decreaseVolume(AudioManager& audio_manager)
{
    if (IsKeyPressed(KEY_O))
    {
        audio_manager.decreaseMasterVolume();
    }
}
