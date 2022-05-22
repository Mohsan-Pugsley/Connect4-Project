#include "Menu.h"
#include "Board.h"
#include <iostream>
using namespace std;

// Board Test: testing the Board class to ensure that a board is printed and updated given inputted values
int main(){  
    // Check if prints option: 1 | rows: 4 | cols: 4 and prints board to exact size
    int board1Cols = 4;
    Board board1(1, 4, board1Cols);
    board1.printBoard();

    // Check if prints option: 2 | rows: 5 | cols: 6 and prints board to exact size
    Board board2(2, 5, 6);
    board2.printBoard();

    // Check if user input matches board size and player option
    Menu menu;
    menu.displayMenu();
    menu.setPlayerOption();
    int playerOption=menu.getPlayerOption();
    menu.setBoardRows();
    int nRows=menu.getBoardRows();
    menu.setBoardColumns();
    int nCols=menu.getBoardColumns();
    Board board3(playerOption, nRows, nCols);
    board3.printBoard();

    // Check if updates board1 with player's tokens 
    board1.updateBoard(3, 'O');
    board1.printBoard();
    for (int i = 0; i < 5; i++) {
        board1.updateBoard(2, 'X');
        if (i == 2) {
            board1.updateBoard(2, 'O');
        }
        board1.printBoard();
    }
    return 0;
}