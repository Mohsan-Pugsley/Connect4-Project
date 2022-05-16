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

    //create player object
    //Player P;
    Person Per;
    Computer C;
    while (gameRunning){
        //person input and print updated board
        Per.move();
        B.updateBoardX(Per.getMove());
        B.printUpdatedBoard();

        //computer input and print updated board
        C.setCols(nCols);
        C.move();
        B.updateBoardO(C.getMove());
        B.printUpdatedBoard();

        int win = B.checkWin();
        if (win == 1){
            cout << "Person has won!" << endl;
            gameRunning = false;
        } else if (win == 2){
            cout << "Computer has won! " << endl;
            gameRunning = false;
        } /*else if (win == 3){
            cout << "It is a tie!" << endl;
            gameRunning = false;
        } */
    }
    return 0;
}