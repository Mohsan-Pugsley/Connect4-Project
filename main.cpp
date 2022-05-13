#include "Game.h"
#include "Computer.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    Game connectGame = Game();
    connectGame.initialize();
    connectGame.runGame();
        
    return 0;
}
