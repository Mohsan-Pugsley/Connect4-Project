#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "Menu.h"
#include "Board.h"
#include "Computer.h"
#include "Person.h"
#include <variant>

class Game {
    private:
        int gameState;
        bool gameRunning;

        bool player1Won;
        bool player2Won;
        bool gameDraw;
        Person* player1;
        Person* player2;
        Computer* computer;
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

        void p1WonCondition();
        void p2WonCondition();
        void drawCondition();

        bool getP1WonFlag();
        bool getP2WonFlag();
        bool getDrawFlag();

        ~Game();
};
 
#endif
