#include "Menu.h"
#include "Board.h"

#include <iostream>
using namespace std;

Board::Board(){  
    Menu M; 
    playerOption=M.getPlayerOption();  
    // Object Board aggregate to Menu class
    int nRows=M.getBoardRows();
    int nCols=M.getBoardColumns();
    // dynamically create an array of size `nRows` - Paris: I searched up how to dynamically allocate a 2D array using new
    board = new char*[nRows];
    // dynamically allocate memory of size `nCols` for each row 
    for (int i = 0; i < nRows; i++) {
        board[i] = new char[nCols];
    }
}

void Board::displayEmptyBoard(){
    cout<<playerOption<<endl;

    if(playerOption==1){
       for (int row=0; row<nRows; row++){
            for (int col=0; col<nCols; col++){
                board[row][col]=' ';
            }
        }
    }
}