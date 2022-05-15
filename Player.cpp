#include "Person.h"
#include "Player.h"
#include "Computer.h"
#include "Board.h"
#include <string>

Player::Player(Board& board,string& name,char& piece){
    newBoard=board;
    newPiece=piece;
}

void Player::SetPiece(const char& piece){
    newPiece=piece;
}

char Player::GetPiece(){
    return newPiece;
}