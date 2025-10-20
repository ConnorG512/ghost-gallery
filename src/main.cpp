#include "game-manager.h"

int main(int argc, char* argv[])
{
    // std::unique_ptr<Window> game_window{ new Window(1600, 900, 60) };
    GameManager game_manager{};

    while (!game_manager.shouldGameClose())
    {
        game_manager.startGameLoop();
    }

    return 0;
}
