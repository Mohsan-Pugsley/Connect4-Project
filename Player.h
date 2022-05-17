#ifndef PLAYER_H
#define PLAYER_H

#include "Menu.h"
#include <iostream>
using namespace std;

class Player{
    public:
        Menu m;
        Player(); //constructor
        virtual ~Player();
        virtual void setCols(int cols);
        virtual void move(bool * full)=0;
        virtual int getMove();
        virtual void setMenu(Menu m);
        virtual bool checkCondition();
        bool ** playerCheck;
        void setPlayerCheck(bool ** playerCheck);
        
        int playerInput;
        
        /*
        void p1Input();
        void p2Input();
        void cInput();

        //void setPlayer1(); // Sets player 1 as person
        //void setPlayer2(); // Sets player 2 depending on selected playerOption
        //int getPlayer1(); // Returns player 1
        //int getPlayer2(;) // Returns player 2

        int getP1Move();
        int getP2Move();
        int getCMove();

        //virtual void move() = 0; //commented virtual to compile menu,board,player and main-board cpp

        bool win(Player*opponent);
        */
        
};

#endif