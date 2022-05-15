#include "Person.h"
#include "Board.h"
#include "Player.h"

Person::Person(Board B):Player(B){
    newBoard = B;
}

int Person::GetMove(){
    int move=newBoard.getHumanMove();
    return move;
}





