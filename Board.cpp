#include "Menu.h"
#include "Board.h"

#include <iostream>
using namespace std;

void Board::displayEmptyBoard(){
    
    // Object Board aggregate to Menu class
    Menu Board;

    int nRows=Board.getBoardRows();
    int nCols=Board.getBoardColumns();
    int playerOption=Board.getPlayerOption();
    
    if(playerOption==1){
        char board[nRows][nCols];

       for (int row=0; row<nRows; row++){
            for (int col=0; col<nCols; col++){
                board[row][col]=' ';
            }
        }
    }
}