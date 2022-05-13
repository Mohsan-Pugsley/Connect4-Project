#include "Game.h"
#include "Menu.h"
#include "Board.h"
#include <iostream>

Game::Game() { // Constructor capable of taking parameters for the default game settings
    player1Won=false;
    player2Won=false;
    gameDraw=false;
}

void Game::initialize() { // Runs code for the initial output of the game, including runGame()
    // Initial sets
    menu.displayMenu();
    menu.setPlayerOption();
    menu.setBoardRows();
    menu.setBoardColumns();
}

void Game::runGame() {  // Runs the code for the game, including the main game loop
    // Construct board
    board = Board(menu.getBoardRows(), menu.getBoardColumns(), menu.getPlayerOption());
    board.printEmptyBoard();

    // sets players based on option
    player1 = new Person();
    if (menu.getPlayerOption() == 1) {
        player2 = new Person();
    } else if (menu.getPlayerOption() == 2) {
        player2 = new Computer();
    }
    setState(1); // game running
    gameRunning = true;
 
    while(gameRunning && (player1Won==false || player2Won==false || gameDraw==false)){
        player1->p1Input();
        // player1->move(); not implemented
        board.printUpdatedBoard(player1->getP1Move());
        // player2->move(); not implemented
        // board.printUpdatedBoard(player2) // unsure how to make colCount function as intended
        //gameRunning = false; // break infinite loop
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

void Game::p1WonCondition(){ // toggled line comment (ctrl + /), just toggled them out to compile for now
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