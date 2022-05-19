#ifndef BOARD_H
#define BOARD_H

//BOARD: prints empty board, prints updated board for player 1 and 2, checks if a player wins and if column is full
class Board{
    int playerOption;
    int nRows;
    char ** board;
    int * colCounter;
    int playerInput;
    int player1Won;
    int player2Won;   
    
    public:
        bool ** check;
        int nCols;
        Board(); // Default constructor
        Board(int rows, int cols, int option); // Constructor for a board  with given rows, cols, and option
        void printEmptyBoard(); // Displays empty game board with dimension from menu input
        void updateBoardX(int inputCol); // Updates gameboard given the desired col to place token X
        void updateBoardO(int inputCol); // Updates gameboard given the desired col to place token O
        void printUpdatedBoard(); // Displays updated board
        int checkWin(); // Returns 1 if player 1 wins, 2 if player 2 wins and 3 if the game is a draw
        bool isColumnFull(int index); // Determines if a column is full of tokens
        void setCheck(); // Initialises the check array
        ~Board(); // Destructor
};

#endif