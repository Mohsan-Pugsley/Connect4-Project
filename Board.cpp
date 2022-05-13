#include "Menu.h"
#include "Board.h"

#include <iostream>
using namespace std;

Board::Board(){  
    
    // Board class aggregate to Menu class
    playerOption=0;
    nRows=0;
    nCols=0;
    // dynamically create an array of size `nRows` - Paris: I searched up how to dynamically allocate a 2D array using new 
                                                // - Viv: moved creation of 2d arry to printEmptyBoard function
    /*board = new char*[nRows];
    // dynamically allocate memory of size `nCols` for each row 
    for (int i = 0; i < nRows; i++) {
        board[i] = new char[nCols];
    }*/
}

void Board::printEmptyBoard(){

    //create menu object
    Menu M;

    //set and assign menu playerOption, board rows and board columns into variables in board class
    M.setPlayerOption();
    playerOption=M.getPlayerOption();

    M.setBoardRows();
    nRows=M.getBoardRows();

    M.setBoardColumns();
    nCols=M.getBoardColumns();

    //create 2d array with dimensions retrieved from menu input
    board = new char*[nRows];
    // dynamically allocate memory of size `nCols` for each row 
    for (int i = 0; i < nRows; i++){
        board[i] = new char[nCols];
    }

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

