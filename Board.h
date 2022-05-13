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
<<<<<<< HEAD
        // Possible constructor? 
        // Board(int xCols, int yRows);
        void displayEmptyBoard();
=======
        void printEmptyBoard(); // displays empty game board with dimension from menu input
        void printBoard();
>>>>>>> 2ac01bf62a22072f20afdfbb609b63ab944ef993
};

#endif