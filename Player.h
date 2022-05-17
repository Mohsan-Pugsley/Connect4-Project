#ifndef PLAYER_H
#define PLAYER_H
//#include "Person.h"
//#include "Computer.h"
#include "Menu.h"
#include <iostream>
using namespace std;

class Player{
    /*
    int player1;
    int player2;
    int computer;
    int comRandCol;
    int comColCount;
    int comLastMoveCol;
    */
   

    public:
        Player(); //constructor
        virtual ~Player();
        virtual void move(bool * full)=0;
        virtual int getMove();
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