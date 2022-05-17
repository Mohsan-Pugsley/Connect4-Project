#include "Menu.h"
#include "Board.h"
#include "Player.h"
#include "Person.h"

#include <iostream>
#include <cassert>
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
void Board::updateBoardX(int inputCol){
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

void Board::updateBoardO(int inputCol){
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

void Board::setCheck(){
     check = new bool*[nRows];
    // dynamically allocate memory of size `cols` for each row 
    for (int i = 0; i < nRows; i++){
        check[i] = new bool[nCols];
    }
    for(int i=0; i<nRows; i++){
        for(int j=0; j<nCols; j++){
            check[i][j] = false;
        }
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

    // checks for diagonal win
    for (int i=0; i<nRows-1; i++){
        for (int j=0; j<nCols-1; j++){
            if(i == j){
                if(board[i][j]=='X'){
                    return 1;
                }else if(board[i][j] == 'O'){
                    return 2;
                }
            }       
        }
    }

    // check for draw
    for (int i=0; i<nRows; i++){
        for (int j=0; j<nCols; j++){
            if(board[i][j] == 'X' || board[i][j] == 'O'){
                check[i][j] = true;
            } else{
                check[i][j] = false;
            }
        }
    }

    for(int i=0; i<nRows; i++){
        for(int j=0; j<nCols; j++){
            if(check[i][j] == false){
                return 0;
            }
        }
    }
    return 3;
}

bool Board::isColumnFull(int index){
    for (int j=0; j<nRows; j++){

            if(check[j][index] == false){
                return false;
            } 
        }
    return true;
}

