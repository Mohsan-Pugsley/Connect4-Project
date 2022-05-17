#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "Game.h"
#include "Menu.h"
#include "Board.h"
#include "Player.h"
#include "Person.h"
#include "Computer.h"

class Game {
    private:
        int gameState;
        bool gameRunning;
 
    public:
        Game(Menu M, Person Per, Computer C);
        void runGame();
        void setState(int state);
        int getState();
        Person Per;
        Computer C;
        Menu M;
        Board B;
        ~Game();
};
 
#endif
