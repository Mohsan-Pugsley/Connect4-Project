#include "Menu.h"
#include "Board.h"
#include "Player.h"

#include <iostream>
using namespace std;

Board::Board(){  
    
    // Board class aggregate to Menu class
    playerOption=0;
    nRows=0;
    nCols=0;
    playerInput=0;

    colCounter= new int[8];
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

<<<<<<< HEAD
void Board::printUpdatedBoard(){

    //initialise column counter to the bottom row
    for(int i=0; i<nCols; i++){
        colCounter[i]=nRows-1;
    }

    Player P;

    P.p1Input();
    playerInput=P.getP1Move();

    //update board: assign token X to the bottom of the chosen column and if there's already a token stack them            
                if(playerInput==1){
                    board[colCounter[0]][playerInput-1]='X';
                    colCounter[0]=colCounter[0]-1;
                } else if (playerInput==2){
                    board[colCounter[1]][playerInput-1]='X';
                    colCounter[1]=colCounter[1]-1;
                }else if(playerInput==3){
                    board[colCounter[2]][playerInput-1]='X';
                    colCounter[2]=colCounter[2]-1;
                }else if (playerInput==4){
                    board[colCounter[3]][playerInput-1]='X';
                    colCounter[3]=colCounter[3]-1;
                }else if(playerInput==5){
                    board[colCounter[4]][playerInput-1]='X';
                    colCounter[4]=colCounter[4]-1;
                }else if(playerInput==6){
                    board[colCounter[5]][playerInput-1]='X';
                    colCounter[5]=colCounter[5]-1;
                }else if(playerInput==7){
                    board[colCounter[6]][playerInput-1]='X';
                    colCounter[6]=colCounter[6]-1;
                }else if(playerInput==8){
                    board[colCounter[7]][playerInput-1]='X';
                    colCounter[7]=colCounter[7]-1;
                } 

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
=======
<<<<<<< HEAD

=======
>>>>>>> ad837a505e56150ce4074dc4dc30a46f8f5adeb1
>>>>>>> f8a215fbc113c099bc7c14a66e27558168dc0bd5
