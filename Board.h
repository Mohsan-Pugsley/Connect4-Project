#ifndef BOARD_H
#define BOARD_H

//Board class: prints empty board, prints updated board
class Board{
    int playerOption;
    int nRows;
    int nCols;
    char ** board;
    int playerInput;
    int * colCounter;
    
    public:
        Board();
        Board(int rows, int cols, int option); //board constructor with parameters
        void printEmptyBoard(); // displays empty game board with dimension from menu input
        void printUpdatedBoard(int inputCol); // updates gameboard given the desired col to place a token
        int GetHumanMove(); //Gives column #
};

#endif