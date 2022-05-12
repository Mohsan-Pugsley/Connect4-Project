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
    //create empty board with input dimensions
    if(playerOption==1){
       for (int row=0; row<nRows; row++){
            for (int col=0; col<nCols; col++){
                board[row][col]=' ';
            }
        }
    //display empty board
    for (int row=0; row<nRows+2; row++){
        for (int col=0; col<nCols; col++){
            if(row<=nRows-1 && col!=nCols-1){
                cout<<'|'<<board[row][col];
            } else if (row<=nRows-1 && col==nCols-1){
                cout<<'|'<<board[row][col]<<'|';
            } else if(row==nRows && col!=nCols-1){
                cout<<'='<<'=';
            } else if (row==nRows && col==nCols-1){
                cout<<'='<<'='<<'=';
            } else if (row==nRows+1 && col!=nCols-1){
                cout<<'|'<<col+1;
            } else if (row==nRows+1 && col==nCols-1){
                cout<<'|'<<col+1<<'|';
            }
        }
        cout<<endl;
        }   
    }
}