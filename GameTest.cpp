#include "Game.h"
#include "Menu.h"
#include "Board.h"
#include "Player.h"
#include "Person.h"
#include "Computer.h"
#include <iostream>
using namespace std;

int main(){
    Menu M;
    Person Per;
    Computer C;

    M.displayMenu();
    B.printBoard();

    bool gameRunning = true;

    M.setPlayerOption();
    int playerOption=M.getPlayerOption();

    M.setBoardRows();
    int nRows=M.getBoardRows();

    M.setBoardColumns();
    int nCols=M.getBoardColumns();

    Player *computer = &C;
    Player *person = &Per;

    Per.setMenu(M);
    C.setMenu(M);
    C.setCols(M.getBoardColumns());
    C.setRows(M.getBoardRows());
    
    Board B(playerOption, nRows, nCols);

    B.printBoard();

    B.setBoardCheck();

    bool *columns = new bool[nCols];
    for(int i=0; i<nCols; i++){
        columns[i] = true;
    }

    int playerTurn = 1;


    // Check if continually loops game until a check win condition is met 
    // Game loop
    while (gameRunning){
        for(int i=0; i<nCols; i++){
            if(B.columnFull(i)){
                columns[i] = false;
            }
        }
        // Person vs Person
        if (playerOption == 1) {
            if (playerTurn == 1) {
                // Person 1 input and print updated board
                Per.setPlayerCheck(B.boardCheck);
                person->move(columns, playerOption);
                B.updateBoard(Per.getMove(), 'X');
                B.printBoard();
                playerTurn = 2;

            } else if (playerTurn == 2) {
                // Person 2 input and print updated board
                Per.setPlayerCheck(B.boardCheck);
                person->move(columns, playerOption);
                B.updateBoard(Per.getMove(), 'O');
                B.printBoard();
                playerTurn = 1;
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
                gameRunning = false;
            }
        } else if (playerOption==2){
            // Person vs Computer
            // Person input and print updated board
            if (playerTurn == 1) {
                // Person 1 input and print updated board
                Per.setPlayerCheck(B.boardCheck);
                person->move(columns, playerOption);
                B.updateBoard(Per.getMove(), 'X');
                B.printBoard();
                playerTurn = 2;

            } else if (playerTurn == 2) {
                // Person 2 input and print updated board
                C.setPlayerCheck(B.boardCheck);
                computer->move(columns, playerOption);
                B.updateBoard(C.getMove(), 'O');
                B.printBoard();
                playerTurn = 1;
            }

            // Initialise win variable
            int win = B.checkWin();
            if (win == 1){
                cout << "You won!" << endl;
                gameRunning = false;
            } else if (win == 2){
                cout << "Computer has won! " << endl;
                gameRunning = false;
            } else if(win ==3){
                cout << "The game is a draw" << endl;
                gameRunning = false;
            }
        }
    }
    return 0;
}