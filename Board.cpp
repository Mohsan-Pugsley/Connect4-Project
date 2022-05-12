#include "Menu.h"
#include "Board.h"

#include <iostream>
using namespace std;

void Board::displayEmptyBoard(){
    
    Menu board;

    int nRows=board.getBoardRows();
    int nCols=board.getBoardColumns();
    
    
    if(Menu::getPlayerOption==1){
        char board[nRows][nCols];
    }
   
    
    //create empty board with input dimensions
        

        for (int row=0; row<nRows; row++){
            for (int col=0; col<nCols; col++){
                board[row][col]=' ';
            }
        }
}