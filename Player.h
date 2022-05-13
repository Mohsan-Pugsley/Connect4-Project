#ifndef PLAYER_H
#define PLAYER_H

#include "Computer.h"
#include <iostream>
using namespace std;

class Player{
    int player1;
    int player2;
    int computer;
    int comRandCol;
    int comColCount;
    int comLastMoveCol;
    public:
        Player(); //constructor
        void p1Input();
        void p2Input();
        void cInput();

        int getP1Move();
        int getP2Move();
        int getCMove();

        bool win(Player*opponent);
        
};

#endif