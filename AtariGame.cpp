#include <string>
#include "Game.h"

int main(void)
{
    std::string tabName = "Breakout Clone";
    int windowWidth = 800;
    int windowHeight = 500;

    Game game(tabName, windowWidth, windowHeight);

    return 0;
}