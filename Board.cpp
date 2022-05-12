#include "Menu.h"
#include "Board.h"

#include <iostream>
using namespace std;

void Board::displayEmptyBoard(){
    
    // Object Board aggregate to Menu class
    Menu M;

    //int nRows=M.getBoardRows();
    int nCols=M.getBoardColumns();
    //int playerOption=M.getPlayerOption();

    cout<<nCols<<endl;

    //board[nRows][nCols];
    
    //if(playerOption==1){
    //   for (int row=0; row<nRows; row++){
    //        for (int col=0; col<nCols; col++){
    //            board[row][col]=' ';
    //        }
    //    }
    //}


}