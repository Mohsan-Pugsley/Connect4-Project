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
        //Player player1;
        //Player player2;

        bool player1Won;
        bool player2Won;
        bool gameDraw;
        Player player1;
        Player player2;
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
