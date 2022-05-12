#include "Game.h"

Game::Game() { // Constructor capable of taking parameters for the default game settings
    bool player1Won=false;
    bool player2Won=false;
    bool gameDraw=false;
}

void Game::initialize() { // Runs code for the initial output of the game, including runGame()


}

void Game::runGame() {  // Runs the code for the game, including the main game loop

    
    while(player1Won==false || player2Won==false || gameDraw==false){
        
    }
}

void Game::setState() { // Sets the state of the gam

}

int Game::getState() { // Returns the state of the game, e.g. 0: Menu, 1: In Progress, 2: Game End

}

void draw() { // Method that runs the necessary code to render the game after an update

}

void refresh() { // Method that refreshes the screen with all the draw changes

}

Game() { // Destructor that deletes any memory if necessary before exiting the game


}