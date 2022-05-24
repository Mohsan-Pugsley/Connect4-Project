#include "Game.h"
#include "Menu.h"
#include "Board.h"
#include "Player.h"
#include "Person.h"
#include "Computer.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]){
    // Initialise Game object
    Game connectGame;

    // Run the Connect 4 Game
    connectGame.runGame();
    
    return 0;
}