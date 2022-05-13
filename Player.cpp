#include "Player.h"
#include "Computer.h"

#include <iostream>
using namespace std;

Player::Player(){
    player1=0;
    player2=0;

    computer=0;
    comRandCol=0;
    comColCount=0;
    comLastMoveCol=0;
}

void Player::p1Input(){
    cout<<"player 1 move: "; 
    cin>>player1;
}

void Player::p2Input(){
    cout<<"player 2 move: "; 
    cin>>player2;
}

void Player::cInput(){
    Computer C;

    cout<<"computer move";

    comRandCol = rand() % comColCount + 1; // + 1 offsets from 0
     if (comRandCol < comLastMoveCol) {
         if (rand() % 3 + 1 < 3) { // 2/3rds of the time
             comRandCol++; // move the randomCol closer to lastMoveCol
         }
     } else if (comRandCol > comLastMoveCol) {
         if (rand() % 3 + 1 < 3) {
             comRandCol--; // move the randomCol closer to lastMoveCol
         }
     } // current result of this is that the computer chooses the edge columns less as well

    cout<<comRandCol;

    computer = comRandCol;
}
        
int Player::getP1Move(){
    return player1;
}
        
int Player::getP2Move(){
    return player2;
}

int Player::getCMove(){
    return computer;
}
