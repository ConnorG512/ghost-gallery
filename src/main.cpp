#include "manager/game-manager.h"

int main(int argc, char* argv[])
{
    GameManager game_manager{};

    while (!game_manager.shouldGameClose())
    {
        game_manager.startGameLoop();
    }

    return 0;
}
