#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
using namespace std;

class Player{
    int player1;
    int player2;
    public:
        Player(); //constructor
        void p1Input();
        void p2Input();
        int getP1Move();
        int getP2Move();


        bool win(Player*opponent);
        
};

#endif