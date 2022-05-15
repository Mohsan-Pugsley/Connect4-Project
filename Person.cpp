#include "Person.h"
#include "Player.h"

Person::Person(Board& board,char& piece):Player(board,piece){
}

int Person::GetMove(){
    int move=board.getHumanMove();
    return move;
}





