#include "Game.h"
#include "Joystick.h"

int main(int argc, char *argv[])
{
    // boostAsioTest();
    Game game;
    if (!game.init())
    {
        return -1;
    }

    game.run();

    game.clean();
    return 0;
}