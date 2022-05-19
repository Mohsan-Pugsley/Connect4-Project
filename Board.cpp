#include "Menu.h"
#include "Board.h"
#include "Player.h"
#include "Person.h"
#include <iostream>
#include <cassert>
using namespace std;

Board::Board(){ 
    // Initialise class variables 
    playerOption=0;
    nRows=0;
    nCols=0;
    playerInput=0;
    player1Won=0;
    player2Won=0;
    board = new char*[8];
    rowCounter= new int[8];

    // Create game board and initialise size 
    for (int i = 0; i < 8; i++){
        board[i] = new char[8];
    }
}

Board::Board(int option, int rows, int cols){ 
    playerOption = option;
    nRows = rows;
    nCols = cols;

    // Empty board with input dimensions
    board = new char*[rows]; 
    for (int i = 0; i < rows; i++){
        board[i] = new char[cols];
    }
    
    // Assign space character to the board array
    for (int r=0; r<rows; r++){
        for (int c=0; c<cols; c++){
            board[r][c]=' ';
        }
    }

    // Column counter with input rows
    rowCounter= new int[cols];
    for(int i=0; i<cols; i++){
        rowCounter[i]=rows-1;
    }

    cout << "Option: " << playerOption << " | Rows: " << nRows << "| Cols: " << nCols << endl;
}


void Board::printEmptyBoard(){
    // Display the empty game board
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

void Board::updateBoard(int inputCol, char inputChar) {
// Assign column that the player inputted
    playerInput = inputCol;

    // Update board: assign token X to the bottom of the chosen column and if there's already a token stack them
    int arrayIndex = inputCol-1;
    board[rowCounter[arrayIndex]][playerInput-1] = inputChar;
    rowCounter[arrayIndex] = rowCounter[arrayIndex] - 1; 
}

void Board::updateBoardX(int inputCol){
    // Assign column that the player inputted
    playerInput = inputCol; 

    // Update board: assign token X to the bottom of the chosen column and if there's already a token stack them            
    switch (playerInput){
            case 1:
                board[rowCounter[0]][playerInput-1]='X';
                rowCounter[0]=rowCounter[0]-1;
                break;
            case 2:
                board[rowCounter[1]][playerInput-1]='X'; 
                rowCounter[1]=rowCounter[1]-1;
                break;
            case 3:
                board[rowCounter[2]][playerInput-1]='X';
                rowCounter[2]=rowCounter[2]-1;
                break;
            case 4:
                board[rowCounter[3]][playerInput-1]='X';
                rowCounter[3]=rowCounter[3]-1;
                break;
            case 5:
                board[rowCounter[4]][playerInput-1]='X';
                rowCounter[4]=rowCounter[4]-1;
                break;
            case 6:
                board[rowCounter[5]][playerInput-1]='X';
                rowCounter[5]=rowCounter[5]-1;
                break;
            case 7:
                board[rowCounter[6]][playerInput-1]='X';
                rowCounter[6]=rowCounter[6]-1;
                break;
            case 8:
                board[rowCounter[7]][playerInput-1]='X';
                rowCounter[7]=rowCounter[7]-1;
                break;
            default:
                cout<<"Invalid input: Not within range.\nTry again: "<<endl; 
                break;     
    } 
}

void Board::updateBoardO(int inputCol){
    // Assign column that the player inputted
    playerInput = inputCol; 

    // Update board: assign token O to the bottom of the chosen column and if there's already a token stack them
    switch (playerInput){
        case 1:
            board[rowCounter[0]][playerInput-1]='O';
            rowCounter[0]=rowCounter[0]-1;
            break;    
        case 2:
            board[rowCounter[1]][playerInput-1]='O'; 
            rowCounter[1]=rowCounter[1]-1;
            break;
        case 3:
            board[rowCounter[2]][playerInput-1]='O';
            rowCounter[2]=rowCounter[2]-1;
            break;
        case 4:
            board[rowCounter[3]][playerInput-1]='O';
            rowCounter[3]=rowCounter[3]-1;
            break;
        case 5:
            board[rowCounter[4]][playerInput-1]='O';
            rowCounter[4]=rowCounter[4]-1;
            break;
        case 6:
            board[rowCounter[5]][playerInput-1]='O';
            rowCounter[5]=rowCounter[5]-1;
            break;
        case 7:
            board[rowCounter[6]][playerInput-1]='O';
            rowCounter[6]=rowCounter[6]-1;
            break;
        case 8:
            board[rowCounter[7]][playerInput-1]='O';
            rowCounter[7]=rowCounter[7]-1;
            break;
        default:
            cout<<"Invalid input: Not within range.\nTry again: "<<endl;
            break;
    }
}

void Board::printUpdatedBoard(){
    // Display the updated board
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
    // Initialise the check array
     check = new bool*[nRows]; 
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
    // Check for vertical win
    for (int i=0; i<nCols-3; i++){ 
        for (int j=0; j<nRows; j++){ 
            if (board[j][i] == 'X' && board[j][i+1] == 'X' && board[j][i+2] == 'X' && board[j][i+3] == 'X'){
                return 1;
            }
            if (board[j][i] == 'O' && board[j][i+1] == 'O' && board[j][i+2] == 'O' && board[j][i+3] == 'O'){
                return 2;
            }
        }
    }

    // Check for horizontal win
    for (int i=0; i<nCols; i++){ 
        for (int j=0; j<nRows-3; j++){ 
            if (board[j][i] == 'X' && board[j+1][i] == 'X' && board[j+1][i] == 'X' && board[j+1][i] == 'X'){
                return 1;
            }
            if (board[j][i] == 'O' && board[j+1][i] == 'O' && board[j+2][i] == 'O' && board[j+3][i] == 'O'){
                return 2;
            }
        }
    }

    // Check for diagonal win
    for (int row=0; row<nRows-3; row++){
        for (int col=0; col<nCols-3; col++){
            if(board[row][col]=='X' && board[row+1][col+1]=='X' && board[row+2][col+2]=='X' && board[row+3][col+3]=='X'){
                return 1;      
            }
        }
    }       
    for (int row=nRows-1; row>=3; row--){
        for (int col=nCols-1; col>=3; col--){
            if (board[row][col]=='X' && board[row-1][col-1]=='X' && board[row-2][col-2]=='X' && board[row-3][col-3]=='X'){
                return 1;
            }
        }
    }
    for (int row=0; row<nRows-3; row++){
        for (int col=0; col<nCols-3; col++){
            if(board[row][col]=='O' && board[row+1][col+1]=='O' && board[row+2][col+2]=='O' && board[row+3][col+3]=='O'){
                return 2;            
            }
        }
    }
    for (int row=nRows-1; row>=3; row--){
        for (int col=nCols-1; col>=3; col--){
            if (board[row][col]=='O' && board[row-1][col-1]=='O' && board[row-2][col-2]=='O' && board[row-3][col-3]=='O'){
                return 2;
            }
        }

    }

    // Check for draw
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
    // Check if column is full
    for (int j=0; j<nRows; j++){
        if(check[j][index] == false){
            return false;
        } 
    }
    return true;
}

