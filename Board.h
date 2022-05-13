#ifndef BOARD_H
#define BOARD_H
#include "Menu.h"

class Board{
    int playerOption;
    int nRows;
    int nCols;
    char ** board;
    int playerInput;

    int * colCounter;
    
    public:
        Board();
        void printEmptyBoard(); // displays empty game board with dimension from menu input
<<<<<<< HEAD
        void printUpdatedBoard(); 
=======
<<<<<<< HEAD
}
=======
        void printBoard();
>>>>>>> f8a215fbc113c099bc7c14a66e27558168dc0bd5
};
>>>>>>> ad837a505e56150ce4074dc4dc30a46f8f5adeb1

#endif