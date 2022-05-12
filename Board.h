#ifndef BOARD_H
#define BOARD_H

#include "Menu.h"

class Board{
    bool player1Won;
    bool player2Won;
    bool gameDraw;

    char ** board;

    public:
        void displayEmptyBoard();
        
};

#endif