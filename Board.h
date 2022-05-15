#ifndef BOARD_H
#define BOARD_H
#include "Menu.h"
#include "Player.h"
#include "Person.h"
#include "Computer.h"

//Board class: prints empty board, prints updated board
class Board{
    int playerOption;
    int nRows;
    int nCols;
    char ** board;
    int * colCounter;
    
    public:
        Board();
        Board(int rows, int cols, int option); //board constructor with parameters
        void printEmptyBoard(); // displays empty game board with dimension from menu input
        void printUpdatedBoard(int inputCol); // updates gameboard given the desired col to place a token
        int GetHumanMove(); //Gives column #
};

#endif