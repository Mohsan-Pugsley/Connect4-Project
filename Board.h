#ifndef BOARD_H
#define BOARD_H
#include "Menu.h"

class Board{
    int playerOption;
    int nRows;
    int nCols;
    char ** board;
    
    public:
        Board();
        void printEmptyBoard(); // displays empty game board with dimension from menu input
}

#endif