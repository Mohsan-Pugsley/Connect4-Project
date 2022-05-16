#include "Menu.h"
#include "Board.h"
#include "Player.h"
#include "Person.h"
#include "Computer.h"

#include <iostream>

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

//stage 2: game
    //assign menu inputs (player option, row, cols) into board class parameters
    Board B(playerOption, nRows, nCols);
    B.printEmptyBoard();
    bool gameRunning = true;

    if(playerOption == 1){
    //create player object
    //Player P;
    Person Player1;
    Person Player2;
    while (gameRunning) {
        //person input and print updated board
        Player1.move();
        B.updateBoardX(Player1.getMove());
        B.printUpdatedBoard();

        //person input and print updated board
        Player2.move();
        B.updateBoardO(Player2.getMove());
        B.printUpdatedBoard();

        int win = B.checkWin();
        if (win == 1){
            cout << "Player 1 has won" << endl;
            gameRunning = false;
        } else if (win == 2){
            cout << "Player 2 has won " << endl;
            gameRunning = false;
        }
    }
    }
    
    if(playerOption == 2){
    //create player object
    //Player P;
    Person Per;
    Computer C;
    while (gameRunning) {
        //person input and print updated board
        Per.move();
        B.updateBoardX(Per.getMove());
        B.printUpdatedBoard();

        //computer input and print updated board
        C.setCols(nCols);
        C.move();
        B.updateBoardO(C.getMove());
        B.printUpdatedBoard();

        B.checkWin();

    }  
    }
    return 0;
}