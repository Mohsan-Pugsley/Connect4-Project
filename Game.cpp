#include "Game.h"
#include "Menu.h"
#include "Board.h"
#include "Player.h"
#include "Person.h"
#include "Computer.h"

Game::Game(){ 
    // Initalise objects 
    Menu M;
    Person Per;
    Computer C;
}

void Game::runGame(){ 
    // Display Menu 
    M.displayMenu();

    B.printBoard();

    // Initialise gameRunning variable
    gameRunning = true;

    // Set and assign menu playerOption, board rows and board columns into variables 
    M.setPlayerOption();
    int playerOption=M.getPlayerOption();

    M.setBoardRows();
    int nRows=M.getBoardRows();

    M.setBoardColumns();
    int nCols=M.getBoardColumns();

    // Create base class pointer to sub class type
    Player *computer = &C;
    Player *person = &Per;

    Per.setMenu(M);
    C.setMenu(M);
    C.setCols(M.getBoardColumns());
    C.setRows(M.getBoardRows());
    
    // Assign menu inputs (player option, row, cols) into board class parameters
    Board B(playerOption, nRows, nCols);

    // Display empty board 
    B.printBoard();

    // Initialise boardCheck
    B.setBoardCheck();

    // Initialise array
    columns = new bool[nCols];
    for(int i=0; i<nCols; i++){
        columns[i] = true;
    }

    playerTurn = 1; // current player's turn

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
}

void Game::setState(int stateNum){ 
    gameState = stateNum;
}

int Game::getState(){ 
    return gameState;
}

Game::~Game(){
    delete[] columns;
}

