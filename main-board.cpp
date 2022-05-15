#include "Menu.h"
#include "Board.h"
#include "Player.h"
#include "Person.h"

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

    //create player object
    Player P;

    //player1 input and print updated board
    P.p1Input();
    int player1Input=P.getP1Move();
    
    B.printUpdatedBoard(player1Input);
    return 0;
}