#include "Player.h"
#include "Person.h"
#include "Computer.h"
#include "Menu.h"

#include <iostream>
using namespace std;

Player::Player(){
    playerInput=0;
}

Player::~Player(){
};

int Player::getMove(){
    return playerInput;
}

void Player::setPlayerCheck(bool ** playerCheck){
    this->playerCheck=playerCheck;
}


void Player::setCols(int cols){

}

void Player::setMenu(Menu m){


}

bool Player::checkCondition(){
    return false;
}