#include "Computer.h"
#include "Board.h"
#include "Player.h"
#include <random>
#include <time.h>
#include <iostream>

Computer::Computer(Board B):Player(B){
    srand(time(NULL)); //seeded number generator
}

int Computer::GetMove(){
    int move=B.getComputerMove();
    return move;
}



