#ifndef BOARD_H
#define BOARD_H

#include "Menu.h"

class Board{

    char ** board;

    int playerOption;

    public:
        Board();
        void displayEmptyBoard();
        
};

#endif