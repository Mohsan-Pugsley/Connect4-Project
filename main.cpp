#include "Game.h"
#include "Menu.h"
#include "Board.h"
#include "Player.h"
#include "Person.h"
#include "Computer.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    Game connectGame(Menu M, Person Per, Computer C);
    connectGame.runGame();
    return 0;
}
