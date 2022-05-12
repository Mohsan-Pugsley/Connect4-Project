#ifndef BOARD_H
#define BOARD_H
#include "Menu.h"

class Board{
    Menu M;
    int nRows;
    int nCols;
    char ** board;
    int playerOption;

    public:
        Board();
        void displayEmptyBoard();
        void printBoard();
};

#endif