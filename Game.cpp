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
    
    // Construct board
    B.printEmptyBoard();

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
    B.printEmptyBoard();

    // Initialise check
    B.setCheck();

    // Initialise array
    array = new bool[nCols];
    
    // Game loop
    while (gameRunning){
        for(int i=0; i<nCols; i++){
            array[i] = true;
            if(B.isColumnFull(i)){
                array[i] = false;
            }
        }

        // Person vs Person
        if(playerOption==1){
            // Person 1 input and print updated board
            Per.setPlayerCheck(B.check);
            person->move(array);
            B.updateBoardX(Per.getMove());
            B.printUpdatedBoard();
            int win = B.checkWin();
            if (win != 1 && win != 2 && win != 3) {
                // Person 2 input and print updated board
                Per.setPlayerCheck(B.check);
                person->move(array);
                B.updateBoardO(Per.getMove());
                B.printUpdatedBoard();
            }
            // Initialise win variable 
            win = B.checkWin();
            if (win == 1){
                cout << "Player 1 has won!" << endl;
                gameRunning = false;
            } else if (win == 2){
                cout << "Player 2 has won! " << endl;
                gameRunning = false;
            } else if(win ==3){
                cout << "The game is a draw" << endl;
            }
        } else {
            // Person vs Computer
            // Person input and print updated board
            Per.setPlayerCheck(B.check);
            person->move(array);
            B.updateBoardX(Per.getMove());
            B.printUpdatedBoard();
            int win = B.checkWin();
            if (win != 1 && win != 2 && win != 3) {
                // Computer input and print updated board
                C.setPlayerCheck(B.check);
                C.setCols(nCols);
                computer->move(array);
                B.updateBoardO(C.getMove());
                B.printUpdatedBoard();
            }
            // Initialise win variable
            win = B.checkWin();
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
    }
}

void Game::setState(int stateNum){ 
    gameState = stateNum;
}

int Game::getState(){ 
    return gameState;
}

Game::~Game(){
    delete[] array;
}

