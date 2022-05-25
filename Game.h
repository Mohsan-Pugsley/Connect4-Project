#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "Menu.h"
#include "Board.h"
#include "Player.h"
#include "Person.h"
#include "Computer.h"
#include "Statistics.h"

// GAME: Runs the Connect 4 Game
class Game {
    private:
        int playerTurn;
        bool gameRunning;
        bool *columns;
    public:
        Game(); // Default Constructor
        void runGame(); // Runs the code for the game, including the main game loop
        ~Game(); // Destructor 
        Player *player; 
        Person P;
        Computer C;
        Menu M;
        Board B;
        Statistics Stats;
};
 
#endif