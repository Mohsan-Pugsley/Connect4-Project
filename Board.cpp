#include "Menu.h"
#include "Board.h"

#include <iostream>
using namespace std;

Board::Board(){
    //Menu M;    
    playerOption=Menu.getPlayerOption();    
}

void Board::displayEmptyBoard(){
    
    // Object Board aggregate to Menu class
    int nRows=Menu.getBoardRows();
    int nCols=Menu.getBoardColumns();


    cout<<playerOption<<endl;

    board[nRows][nCols];
    
    if(playerOption==1){
       for (int row=0; row<nRows; row++){
            for (int col=0; col<nCols; col++){
                board[row][col]=' ';
            }
        }
    }
}