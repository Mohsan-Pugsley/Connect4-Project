#include "Person.h"
#include "Board.h"
#include "Player.h"

Person::Person(Board B):Player(B){
}

int Person::GetMove(){
    int move=B.getHumanMove();
    return move;
}





