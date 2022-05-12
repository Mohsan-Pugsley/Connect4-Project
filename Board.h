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
        // Possible constructor? 
        // Board(int xCols, int yRows);
        void displayEmptyBoard();
        void printBoard();
};

#endif