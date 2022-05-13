#include "Game.h"
#include "Computer.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    Game connectGame = Game();
    connectGame.initialize();
    connectGame.runGame();

    Computer cmp = Computer();
    for (int i = 0; i < 25; i++) {
        cmp.move();
        cout << "The computer has chosen column: " << cmp.getTurn() << endl;
    }
        
    return 0;
}
