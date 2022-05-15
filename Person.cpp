#include "Person.h"
#include "Player.h"

Person::Person(Board& board):Player(board){
}

int Person::GetMove(){
    int move=board.getHumanMove();
    return move;
}





