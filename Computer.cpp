#include "Computer.h"
#include "Board.h"
#include <random>
#include <time.h>
#include <iostream>

Computer::Computer(Board& board):Player(board){
    srand(time(NULL)); //seeded number generator
}

int Computer::GetMove(){
    int move=board.getComputerMove();
    return move;
}



