#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "Menu.h"
#include "Board.h"

class Game {
    private:
        int gameState;
        bool gameRunning;
        //Player player1;
        //Player player2;
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