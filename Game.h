#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "Menu.h"
#include "Board.h"
#include "Computer.h"
#include "Person.h"
 
class Game {
    private:
        int gameState;
        bool gameRunning;
        Person player1;
        Computer computer;
        Menu menu;
        Board board;
 
    public:
        Game();
        void initialize();
        void runGame();
        void setState(int state);
        int getState();
        void draw();
        void refresh();
        ~Game();
};
 
#endif
