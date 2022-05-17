#include "Player.h"
#include "Menu.h"

#include <iostream>
using namespace std;

Player::Player(){
    // Initialise variable
    playerInput=0;
}

int Player::getMove(){
    return playerInput;
}

void Player::setPlayerCheck(bool ** playerCheck){
    // Retrieve playerCheck
    this->playerCheck=playerCheck;
}


