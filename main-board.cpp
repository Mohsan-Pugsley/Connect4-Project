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

        if(B.updateBoardX(Per.getMove())==1){
            gameRunning=false;
            cout<<"Player 1 Won"<<endl;
        } else if (B.updateBoardO(C.getMove())==2){
            gameRunning=false;
            cout<<"Player 2 Won"<<endl;
        }


       // B.checkWinX();
       // B.checkWinO();

    }

    return 0;
}