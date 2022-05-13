#include "Game.h"
#include "Menu.h"
#include "Board.h"

Game::Game() { // Constructor capable of taking parameters for the default game settings
    // player1 = Player;
    // player2 = Player;

    bool player1Won=false;
    bool player2Won=false;
    bool gameDraw=false;
}

void Game::initialize() { // Runs code for the initial output of the game, including runGame()
    // Initial sets
    menu.displayMenu();
}

void Game::runGame() {  // Runs the code for the game, including the main game loop
    // Construct board
    board.printEmptyBoard();
    //player1 = new Person();

    gameRunning = true;

    while(gameRunning && (player1Won==false || player2Won==false || gameDraw==false)){
        gameRunning = false; // break infinite loop
    }
}

void Game::setState(int stateNum) { // Sets the state of the game
    gameState = stateNum;
}

int Game::getState() { // Returns the state of the game, e.g. 0: Menu, 1: In Progress, 2: Game End
    return gameState;
}

void Game::draw() { // Method that runs the necessary code to render the game after an update
    // menu.draw()
    // board.draw()
}

void Game::refresh() { // Method that refreshes the screen with all the draw changes (ncurses only)
    // menu.refresh()
    // board.refres()
}

Game::~Game() { // Destructor that deletes any memory if necessary before exiting the game
    // TODO?
}

void Game::p1WonCondition(){ // toggle line comment (ctrl + /), just toggled them out to compile for now
    // Menu M;

    // M.setPlayerOption();
    // playerOption=M.getPlayerOption();

    // M.setBoardRows();
    // nRows=M.getBoardRows();

    // M.setBoardColumns();
    // nCols=M.getBoardColumns();

    // Board B;

    // B.printEmptyBoard();
    // B.printUpdatedBoard();


    // for (int row=0; row<nRows; row++){
    //     for (int col=0; col<nCols; col++){
    //         if(board[row][col]=='X' && board[row][col+1]=='X' && board[row][col+2]=='X' && board[row][col+3]=='X'){
    //                 cout<<"Player 1 Wins (4 horiztonally)"<<endl;
    //             return player1Won=true;
    //         }
    //     }
    // }

    // //if player 1 gets 4 in a row vertically
    // for (int row=0; row<nRows; row++){
    //     for (int col=0; col<nCols; col++){
    //         if(board[row][col]=='X' && board[row+1][col]=='X' && board[row+2][col]=='X' && board[row+3][col]=='X'){
    //             cout<<"Player 1 Wins (4 vertically)"<<endl;
    //             return player1Won=true;
    //         }
    //     }
    // }

    //if player 1 gets 4 in a row diagonally
    // for (int row=0; row<nRows; row++){
    //     for (int col=0; col<nCols; col++){
    //         if(board[row][col]=='X' && board[row+1][col+1]=='X' && board[row+2][col+2]=='X' && board[row+3][col+3]=='X'){
    //             cout<<"Player 1 Wins (4 diagonally (-)slope)"<<endl;
    //             return player1Won=true;
    //         } else if (board[row][col]=='X' && board[row-1][col+1]=='X' && board[row-2][col+2]=='X' && board[row-3][col+3]=='X'){
    //             cout<<"Player 1 Wins (4 diagonally (+)slope)"<<endl;
    //             return player1Won=true;
    //         }
    //     }
    // }
}

void p2WonCondition(){

}

void drawCondition(){

}

bool Game::getP1WonFlag(){
    return player1Won;
}

bool Game::getP2WonFlag(){
    return player2Won;
}

bool Game::getDrawFlag(){
    return gameDraw;
}