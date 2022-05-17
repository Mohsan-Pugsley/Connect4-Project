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
    
    Player *person = new Person();
    Player *computer = new Computer();
    
    person->setMenu(M);

    computer->setMenu(M);
    computer->setCols(M.getBoardColumns());
    
//stage 2: game
    //assign menu inputs (player option, row, cols) into board class parameters
    Board B(playerOption, nRows, nCols);
    B.printEmptyBoard();
    bool gameRunning = true;
    bool *array = new bool[nCols];
    B.setCheck();
    
    while (gameRunning){
        for(int i=0; i<nCols; i++){
            array[i] = true;
            if(B.isColumnFull(i)){
                array[i] = false;
            }
        }
        //person input and print updated board
        person->setPlayerCheck(B.check);
        person->move(array);
    
        B.updateBoardX(person->getMove());
        B.printUpdatedBoard();
        //computer input and print updated board
        computer->setPlayerCheck(B.check);
        computer->move(array);
        B.updateBoardO(computer->getMove());
        B.printUpdatedBoard();

         int win = B.checkWin();
         if (win == 1){
             cout << "Person has won!" << endl;
             gameRunning = false;
        } else if (win == 2){
            cout << "Computer has won! " << endl;
            gameRunning = false;
        } else if(win ==3){
            cout << "The game is a draw" << endl;
        }  
    }
    return 0;
}