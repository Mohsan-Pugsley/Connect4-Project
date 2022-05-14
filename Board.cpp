#include "Menu.h"
#include "Board.h"
#include "Player.h"
#include "Person.h"

#include <iostream>
using namespace std;

//Board default constructor
Board::Board(){ 
    //initialise class variables 
    playerOption=0;
    nRows=0;
    nCols=0;
    playerInput=0;

    colCounter= new int[8];
}

Board::Board(int option, int rows, int cols) { // constructs a Board given parameters
    playerOption = option;
    nRows = rows;
    nCols = cols;
    colCounter= new int[rows];
    cout << "Option: " << playerOption << " | Rows: " << nRows << "| Cols: " << nCols << endl;
}

//prints empty board with given parameters
void Board::printEmptyBoard(){

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
    //initialise column counter to the bottom row
    for(int i=0; i<nRows; i++){
        colCounter[i]=nRows-1;
    }
}

//prints updated board with player input
void Board::printUpdatedBoard(int inputCol){
    playerInput = inputCol; // col that the a player input

    //update board: assign token X to the bottom of the chosen column and if there's already a token stack them            
        switch (playerInput){
            case 1:
                board[colCounter[0]][playerInput-1]='X';
                colCounter[0]=colCounter[0]-1;
                break;    
            case 2:
                board[colCounter[1]][playerInput-1]='X'; 
                colCounter[1]=colCounter[1]-1;
                break;
            case 3:
                board[colCounter[2]][playerInput-1]='X';
                colCounter[2]=colCounter[2]-1;
                break;
            case 4:
                board[colCounter[3]][playerInput-1]='X';
                colCounter[3]=colCounter[3]-1;
                break;
            case 5:
                board[colCounter[4]][playerInput-1]='X';
                colCounter[4]=colCounter[4]-1;
                break;
            case 6:
                board[colCounter[5]][playerInput-1]='X';
                colCounter[5]=colCounter[5]-1;
                break;
            case 7:
                board[colCounter[6]][playerInput-1]='X';
                colCounter[6]=colCounter[6]-1;
                break;
            case 8:
                board[colCounter[7]][playerInput-1]='X';
                colCounter[7]=colCounter[7]-1;
                break;
        }

        // update board for player 2
        /*switch (playerInput){
            case 1:
                board[colCounter[0]][playerInput-1]='O';
                colCounter[0]=colCounter[0]-1;
                break;    
            case 2:
                board[colCounter[1]][playerInput-1]='O'; 
                colCounter[1]=colCounter[1]-1;
                break;
            case 3:
                board[colCounter[2]][playerInput-1]='O';
                colCounter[2]=colCounter[2]-1;
                break;
            case 4:
                board[colCounter[3]][playerInput-1]='O';
                colCounter[3]=colCounter[3]-1;
                break;
            case 5:
                board[colCounter[4]][playerInput-1]='O';
                colCounter[4]=colCounter[4]-1;
                break;
            case 6:
                board[colCounter[5]][playerInput-1]='O';
                colCounter[5]=colCounter[5]-1;
                break;
            case 7:
                board[colCounter[6]][playerInput-1]='O';
                colCounter[6]=colCounter[6]-1;
                break;
            case 8:
                board[colCounter[7]][playerInput-1]='O';
                colCounter[7]=colCounter[7]-1;
                break;
        }*/

    //display the update board
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