#include "Player.h"
#include "Menu.h"
#include <iostream>
using namespace std;

Player::Player(){
    playerInput=0;
}

int Player::getMove(){
    return playerInput;
}

Player::~Player(){
};


