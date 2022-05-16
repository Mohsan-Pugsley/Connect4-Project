#ifndef BOARD_H
#define BOARD_H

//Board class: prints empty board, prints updated board
class Board{
    int playerOption;
    int nRows;
    int nCols;
    char ** board;
    int * colCounter;
    int playerInput;

    
    public:
        Board();
        Board(int rows, int cols, int option); //board constructor with parameters
        void printEmptyBoard(); // displays empty game board with dimension from menu input
        void updateBoardX(int inputCol); // updates gameboard given the desired col to place a token
        void updateBoardO(int inputCol);
        void printUpdatedBoard();//display updated board
        bool checkWinX();
        bool checkWinO();
};

#endif