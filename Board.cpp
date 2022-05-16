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
    player1Won=0;
    player2Won=0;
    board = new char*[8];
    // dynamically allocate memory of size `nCols` for each row 
    for (int i = 0; i < 8; i++){
        board[i] = new char[8];
    }

    colCounter= new int[8];
}

Board::Board(int option, int rows, int cols) { // constructs a Board given parameters
    playerOption = option;
    nRows = rows;
    nCols = cols;

    //empty board with input dimensions
    board = new char*[rows];
    // dynamically allocate memory of size `cols` for each row 
    for (int i = 0; i < rows; i++){
        board[i] = new char[cols];
    }
    //assign space character to board array
    for (int r=0; r<rows; r++){
        for (int c=0; c<cols; c++){
            board[r][c]=' ';
        }
    }

    //column counter with input rows
    colCounter= new int[cols];
    for(int i=0; i<cols; i++){
        colCounter[i]=rows-1;
    }

    cout << "Option: " << playerOption << " | Rows: " << nRows << "| Cols: " << nCols << endl;
}

//prints empty board with given parameters
void Board::printEmptyBoard(){
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

//prints updated board with player input
int Board::updateBoardX(int inputCol){
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
            default:
                cout<<"Invalid input: Not within range.\nTry again: "<<endl; 
                break;     
    } 
}

int Board::updateBoardO(int inputCol){
    playerInput = inputCol; // col that the a player input

    switch (playerInput){
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
        default:
            cout<<"Invalid input: Not within range.\nTry again: "<<endl;
            break;
    }
}

void Board::printUpdatedBoard(){
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

int Board::checkWin(){
    //checks for vertical win
    for (int i=0; i<nCols-3; i++){ // columns
        for (int j=0; j<nRows; j++){ // rows
            if (board[j][i] == 'X' && board[j][i+1] == 'X' && board[j][i+2] == 'X' && board[j][i+3] == 'X'){
                return 1;
            }
            if (board[j][i] == 'O' && board[j][i+1] == 'O' && board[j][i+2] == 'O' && board[j][i+3] == 'O'){
                return 2;
            }
        }
    }

    //checks for horizontal win
    for (int i=0; i<nCols; i++){ // columns
        for (int j=0; j<nRows-3; j++){ // rows
            if (board[j][i] == 'X' && board[j+1][i] == 'X' && board[j+1][i] == 'X' && board[j+1][i] == 'X'){
                return 1;
            }
            if (board[j][i] == 'O' && board[j+1][i] == 'O' && board[j+2][i] == 'O' && board[j+3][i] == 'O'){
                return 2;
            }
        }
    }
    return 0;
}

/*
bool Board::checkWinX(){
    //if player 1 gets 4 in a row horizontally
                for (int row=0; row<nRows; row++){
                    for (int col=0; col<nCols; col++){
                        if(board[row][col]=='X' && board[row][col+1]=='X' && board[row][col+2]=='X' && board[row][col+3]=='X'){
                            cout<<"Player 1 Wins (4 horiztonally)"<<endl;
                            return player1Won=true;
                        }
                    }
                }

                //if player 1 gets 4 in a row vertically
                for (int row=0; row<nRows; row++){
                    for (int col=0; col<nCols; col++){
                        if(board[row][col]=='X' && board[row+1][col]=='X' && board[row+2][col]=='X' && board[row+3][col]=='X'){
                            cout<<"Player 1 Wins (4 vertically)"<<endl;
                            return player1Won=true;
                        }
                    }
                }

                //if player 1 gets 4 in a row diagonally
                for (int row=0; row<nRows; row++){
                    for (int col=0; col<nCols; col++){
                        if(board[row][col]=='X' && board[row+1][col+1]=='X' && board[row+2][col+2]=='X' && board[row+3][col+3]=='X'){
                            cout<<"Player 1 Wins (4 diagonally (-)slope)"<<endl;
                            return player1Won=true;
                        } else if (board[row][col]=='X' && board[row-1][col+1]=='X' && board[row-2][col+2]=='X' && board[row-3][col+3]=='X'){
                            cout<<"Player 1 Wins (4 diagonally (+)slope)"<<endl;
                            return player1Won=true;
                        }
                    }
                }
    return 0;

}

bool Board::checkWinO(){
                //if player 2 gets 4 in a row horizontally
                for (int row=0; row<nRows; row++){
                    for (int col=0; col<nCols; col++){
                        if(board[row][col]=='O' && board[row][col+1]=='O' && board[row][col+2]=='O' && board[row][col+3]=='O'){
                            cout<<"Player 2 Wins (4 horizontally)"<<endl;

                            return player2Won=true;
                        }
                    }
                }

                //if player 2 gets 4 in a row vertically
                for (int row=0; row<nRows; row++){
                    for (int col=0; col<nCols; col++){
                        if(board[row][col]=='O' && board[row+1][col]=='O' && board[row+2][col]=='O' && board[row+3][col]=='O'){
                            cout<<"Player 2 Wins (4 vertically)"<<endl;
                            return player2Won=true;
                        }
                    }
                }

                //if player 2 gets 4 in a row diagonally
                for (int row=0; row<nRows; row++){
                    for (int col=0; col<nCols; col++){
                        if(board[row][col]=='O' && board[row+1][col+1]=='O' && board[row+2][col+2]=='O' && board[row+3][col+3]=='O'){
                            cout<<"Player 2 Wins (4 diagonally (-)slope)"<<endl;
                            return player2Won=true;
                        } else if (board[row][col]=='O' && board[row-1][col+1]=='O' && board[row-2][col+2]=='O' && board[row-3][col+3]=='O'){
                            cout<<"Player 2 Wins (4 diagonally (+)slope)"<<endl;
                            return player2Won=true;
                        }
                    }
                }
    return 0;
}
*/