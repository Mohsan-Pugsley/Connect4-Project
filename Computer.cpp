#include "Computer.h"
#include "Board.h"
#include <random>
#include <time.h>
#include <iostream>

Computer::Computer(Board& board, char& piece):Player(board,"Mr. Acer",piece)
{
    //Seed random number generator for its random number selections
    srand(static_cast<unsigned int>(time(0))); //seeded number generator
}

int Computer::GetMove(){
    int move=board.getComputerMove();
    return move;
}


