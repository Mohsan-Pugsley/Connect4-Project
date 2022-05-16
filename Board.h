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
    int player1Won;
    int player2Won;
    
    public:
        Board();
        Board(int rows, int cols, int option); //board constructor with parameters
        void printEmptyBoard(); // displays empty game board with dimension from menu input
        int updateBoardX(int inputCol); // updates gameboard given the desired col to place a token
        int updateBoardO(int inputCol);
        void printUpdatedBoard();//display updated board
        int checkWin(); 
        /*
        bool checkWinX();
        bool checkWinO();
        */
};

#endif