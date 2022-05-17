#ifndef BOARD_H
#define BOARD_H

//BOARD class: prints empty board, prints updated board for player 1 and 2, checks if a player wins and if column is full
class Board{
    int playerOption;
    int nRows;
    char ** board;
    int * colCounter;
    int playerInput;
    int player1Won;
    int player2Won;
    
    //bool ** full;
    
    public:
        bool ** check;
        int nCols;
        Board();
        Board(int rows, int cols, int option); //board constructor with parameters
        void printEmptyBoard(); // displays empty game board with dimension from menu input
        void updateBoardX(int inputCol); // updates gameboard given the desired col to place token X
        void updateBoardO(int inputCol);// updates gameboard given the desired col to place token O
        void printUpdatedBoard();//display updated board
        int checkWin(); //return 1 if player 1 wins, 2 if player 2 wins and 3 if draw
        bool isColumnFull(int index); //determines if a column is full of tokens
        void setCheck(); //initialise check array
};

#endif