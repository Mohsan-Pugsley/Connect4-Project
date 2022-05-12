#include "Game.h"
#include "Menu.h"
#include "Board.h"

Game::Game() { // Constructor capable of taking parameters for the default game settings
    menu = Menu;
    // player1 = Player;
    // player2 = Player;
}

void Game::initialize() { // Runs code for the initial output of the game, including runGame()

}

void Game::runGame() {  // Runs the code for the game, including the main game loop
    // Initial gets
    menu.displayMenu();
    menu.setPlayerOption();
    menu.setBoardSize();

    // Construct board
    board = Board(menu.getBoardColumns(), menu.getBoardRows());
    board.displayEmptyBoard();
    
    while(player1Won==false || player2Won==false || gameDraw==false){
        // TODO: game loop something goes here
    }
}

void Game::setState(int stateNum) { // Sets the state of the game
    gameState = stateNum;
}

int Game::getState() { // Returns the state of the game, e.g. 0: Menu, 1: In Progress, 2: Game End

}

void Game::draw() { // Method that runs the necessary code to render the game after an update

}

void Game::refresh() { // Method that refreshes the screen with all the draw changes

}

Game::~Game() { // Destructor that deletes any memory if necessary before exiting the game


}