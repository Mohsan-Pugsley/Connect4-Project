#include "Menu.h"
#include "Board.h"
#include <iostream>
using namespace std;

int main(){  
    // Check if prints option: 1 | rows: 4 | cols: 4 and prints board to exact size
    Board board1(1, 4, 4);
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

    return 0;
}