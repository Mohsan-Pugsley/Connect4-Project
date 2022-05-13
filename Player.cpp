#include "Player.h"

Player::Player(){
    player1=0;
    player2=0;
}

void Player::p1Input(){
    cout<<"player 1 move: "; 
    cin>>player1;
}

void Player::p2Input(){
    cout<<"player 2 move: "; 
    cin>>player2;
}
        
int Player::getP1Move(){
    return player1;
}
        
int Player::getP2Move(){
    return player2;
}