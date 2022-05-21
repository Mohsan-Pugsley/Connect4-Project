#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "Menu.h"
#include "Board.h"
#include "Player.h"
#include "Person.h"
#include "Computer.h"

// GAME: Runs the Connect 4 Game
class Game {
    private:
        int gameState;
        int playerTurn;
        bool gameRunning;
        bool *columns;
    public:
        Game(); // Default Constructor
        void setState(int state); // Sets the state of the game
        void runGame(); // Runs the code for the game, including the main game loop
        int getState(); // Returns the state of the game, e.g. 0: Menu, 1: In Progress, 2: Game End
        ~Game(); // Destructor 
        Player *player; 
        Person Per;
        Computer C;
        Menu M;
        Board B;
};
 
#endif
