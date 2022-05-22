#include "Menu.h"
#include "Board.h"
#include "Player.h"
#include "Person.h"
#include "Computer.h"

#include <iostream>

// Tests the entire game 
int main(){
//stage 1: menu
    Menu M;
    M.displayMenu();

    //set and assign menu playerOption, board rows and board columns into variables in main
    M.setPlayerOption();
    int playerOption=M.getPlayerOption();

    M.setBoardRows();
    int nRows=M.getBoardRows();

    M.setBoardColumns();
    int nCols=M.getBoardColumns();

    Person Per;
    Per.setMenu(M);

    Computer C;
    C.setMenu(M);
    C.setCols(M.getBoardColumns());
    C.setRows(M.getBoardRows());
    
//stage 2: game
    //assign menu inputs (player option, row, cols) into board class parameters
    Board B(playerOption, nRows, nCols);
    B.printBoard();
    bool gameRunning = true;
    bool *array = new bool[nCols];
    B.setBoardCheck();
    
    while (gameRunning){
        for(int i=0; i<nCols; i++){
            array[i] = true;
            if(B.columnFull(i)){
                array[i] = false;
            }
        }

        if(playerOption==1){
            //person1 input and print updated board
            Per.setPlayerCheck(B.boardCheck);
            Per.move(array);
            B.updateBoard(Per.getMove(), 'X');
            B.printBoard();
            //person2 input and print updated board
            Per.setPlayerCheck(B.boardCheck);
            Per.move(array);
            B.updateBoard(Per.getMove(),'O');
            B.printBoard();

        } else {
            //person1 input and print updated board
            Per.setPlayerCheck(B.boardCheck);
            Per.move(array);
            B.updateBoard(Per.getMove(),'X');
            B.printBoard();
            //computer input and print updated board
            C.setPlayerCheck(B.boardCheck);
            C.setCols(nCols);
            C.move(array);
            B.updateBoard(C.getMove(),'O');
            B.printBoard();
        }

         int win = B.checkWin();
         if (win == 1){
             cout << "Player 1 has won!" << endl;
             gameRunning = false;
        } else if (win == 2){
            cout << "Player 2 has won! " << endl;
            gameRunning = false;
        } else if(win ==3){
            cout << "The game is a draw" << endl;
        }
        
    }
    return 0;
}