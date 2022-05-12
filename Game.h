#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "Menu.h"
#include "Board.h"
class Game {
    private:
        bool gameState;
        //Player player1;
        //Player player2;
        Menu menu;
        Board board;

    public:
        Game();
        void initialize();
        void runGame();
        void setState();
        void getState();
        void draw();
        void refresh();
        ~Game();
};

#endif