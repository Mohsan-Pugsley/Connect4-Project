#include "Game.h"
#include "Menu.h"
#include "Board.h"
#include "Player.h"
#include "Person.h"
#include "Computer.h"

Game::Game(){ // Constructor capable of taking parameters for the default game settings
    Menu M;
    Person Per;
    Computer C;
}

void Game::runGame() {  // Runs the code for the game, including the main game loop
    M.displayMenu();
    // Construct board
    B.printEmptyBoard();
    gameRunning = true;

    //set and assign menu playerOption, board rows and board columns into variables in main
    M.setPlayerOption();
    int playerOption=M.getPlayerOption();

    M.setBoardRows();
    int nRows=M.getBoardRows();

    M.setBoardColumns();
    int nCols=M.getBoardColumns();

    Per.setMenu(M);

    C.setMenu(M);
    C.setCols(M.getBoardColumns());
    C.setRows(M.getBoardRows());
    
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

        if(playerOption==1){
            //person1 input and print updated board
            Per.setPlayerCheck(B.check);
            Per.move(array);
            B.updateBoardX(Per.getMove());
            B.printUpdatedBoard();
            int win = B.checkWin();
            if (win != 1 && win != 2 && win != 3) {
                //person2 input and print updated board
                Per.setPlayerCheck(B.check);
                Per.move(array);
                B.updateBoardO(Per.getMove());
                B.printUpdatedBoard();
            }
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
            // option 2
            //person1 input and print updated board
            Per.setPlayerCheck(B.check);
            Per.move(array);
            B.updateBoardX(Per.getMove());
            B.printUpdatedBoard();
            int win = B.checkWin();
            if (win != 1 && win != 2 && win != 3) {
                //computer input and print updated board
                C.setPlayerCheck(B.check);
                C.setCols(nCols);
                C.move(array);
                B.updateBoardO(C.getMove());
                B.printUpdatedBoard();
            }
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

void Game::setState(int stateNum) { // Sets the state of the game
    gameState = stateNum;
}

int Game::getState() { // Returns the state of the game, e.g. 0: Menu, 1: In Progress, 2: Game End
    return gameState;
}


Game::~Game() { // Destructor that deletes any memory if necessary before exiting the game
    // TODO?
}

