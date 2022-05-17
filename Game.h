#ifndef GAME_H
#define GAME_H
#include <iostream>
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
        Game();
        void setState(int state);
        void runGame();
        int getState();
        Person Per;
        Computer C;
        Menu M;
        Board B;
        ~Game();
};
 
#endif
